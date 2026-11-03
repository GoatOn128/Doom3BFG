/*
 * pcx.h - single-header ZSoft PCX loader. C99 / C++11. No platform dependencies.
 *
 * Usage:
 *     PCXImage img;
 *     if (pcx_parse(buf, size, &img) == PCX_OK) {
 *         uint8_t *rgba = malloc(pcx_rgba_size(&img));
 *         pcx_decode_rgba(&img, rgba);              // any supported format -> RGBA8
 *     }
 *   or
 *     uint8_t *rgba = pcx_load_rgba(buf, size, &w, &h, &err);   // free with pcx_free()
 *   or, for indexed images (keeps palette indices):
 *     pcx_decode_indexed(&img, indices /w*h/, palette /256, optional/);
 *
 * PCXImage keeps pointers into `buf`; keep the buffer alive until decoding is done.
 *
 * Supported:
 *   - Versions 0, 2, 3, 4, 5 (version selects palette source, see pcx_palette)
 *   - Encoding 1 (RLE) and 0 (raw, rare)
 *   - Indexed: bits_per_plane * planes <= 8
 *       1x1 (mono), 2x1, 4x1, 8x1 (256 colour, VGA palette trailer),
 *       1x2, 1x3, 1x4 (EGA planar), other combinations with <= 8 total bits
 *   - 24-bit RGB (8 bits x 3 planes), 32-bit RGBA (8 bits x 4 planes)
 *   - Arbitrary bytes_per_line (padding stripped), odd or even
 *   - Little-endian parsing independent of host endianness / struct packing
 *   - All input is bounds-checked; no asserts, errors are returned
 *
 * Not supported (returns PCX_ERR_UNSUPPORTED):
 *   - bits_per_plane * planes > 8 for non-truecolor (e.g. 4 bits x 4 planes)
 *   - 8 bits x 2 planes, truecolor with bits != 8
 *   - CGA header palette mode (bytes 16/19). 2-bit images use the plain header palette.
 *   - DCX multi-page containers
 *
 * Overridable macros (define before including): PCX_MALLOC(n), PCX_FREE(p).
 * All functions are static inline; define PCX_H guard collisions are the only
 * cross-TU concern.
 */
#ifndef PCX_H
#define PCX_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#if !defined(PCX_MALLOC) || !defined(PCX_FREE)
#include <stdlib.h>
#undef  PCX_MALLOC
#undef  PCX_FREE
#define PCX_MALLOC(n) malloc(n)
#define PCX_FREE(p)   free(p)
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define PCX_HEADER_SIZE 128

typedef enum PCXError
{
    PCX_OK = 0,
    PCX_ERR_ARGS,
    PCX_ERR_TOO_SMALL,
    PCX_ERR_BAD_MAGIC,
    PCX_ERR_BAD_ENCODING,
    PCX_ERR_BAD_HEADER,
    PCX_ERR_UNSUPPORTED,
    PCX_ERR_TOO_LARGE,
    PCX_ERR_TRUNCATED,
    PCX_ERR_NOMEM,
    PCX_ERR_NOT_INDEXED
} PCXError;

typedef enum PCXFormat
{
    PCX_FORMAT_INDEXED = 1,
    PCX_FORMAT_RGB,
    PCX_FORMAT_RGBA
} PCXFormat;

typedef struct PCXColor
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
} PCXColor;

typedef struct PCXImage
{
    const uint8_t *data;        /* start of pixel stream (buf + 128)                  */
    const uint8_t *data_end;    /* end of pixel stream (excludes VGA palette trailer) */
    const uint8_t *vga_pal;     /* 768 bytes RGB, or NULL                             */
    uint32_t width;
    uint32_t height;
    int32_t  x_min;
    int32_t  y_min;
    uint16_t bytes_per_line;    /* per plane                                          */
    uint16_t hdpi;
    uint16_t vdpi;
    uint16_t palette_type;      /* 1 = colour/BW, 2 = grayscale                       */
    uint8_t  version;
    uint8_t  encoding;          /* 0 raw, 1 RLE                                       */
    uint8_t  bits_per_plane;
    uint8_t  planes;
    uint8_t  index_bits;        /* bits_per_plane * planes, indexed only              */
    uint8_t  format;            /* PCXFormat                                          */
    uint8_t  header_pal[48];    /* 16-colour EGA palette from the header              */
} PCXImage;

/* ------------------------------------------------------------------------- */
/* Internals                                                                 */
/* ------------------------------------------------------------------------- */

static inline uint16_t pcx__u16(const uint8_t *p)
{
    return (uint16_t)((unsigned)p[0] | ((unsigned)p[1] << 8));
}

static inline int32_t pcx__s16(const uint8_t *p)
{
    int32_t v = (int32_t)pcx__u16(p);
    return v >= 0x8000 ? v - 0x10000 : v;
}

static inline size_t pcx__row_bytes(const PCXImage *img)
{
    return (size_t)img->planes * (size_t)img->bytes_per_line;
}

typedef struct PCXReader
{
    const uint8_t *p;
    const uint8_t *end;
    uint32_t       run;
    uint8_t        value;
    uint8_t        raw;
} PCXReader;

static inline void pcx__reader_init(PCXReader *r, const PCXImage *img)
{
    r->p     = img->data;
    r->end   = img->data_end;
    r->run   = 0;
    r->value = 0;
    r->raw   = (uint8_t)(img->encoding == 0);
}

/* Fills exactly n bytes. Run state carries across calls so encoders that let a
 * run span scanlines are handled. Zero-length runs are skipped. */
static inline PCXError pcx__read_row(PCXReader *r, uint8_t *dst, size_t n)
{
    if (r->raw)
    {
        if ((size_t)(r->end - r->p) < n)
            return PCX_ERR_TRUNCATED;
        memcpy(dst, r->p, n);
        r->p += n;
        return PCX_OK;
    }

    while (n)
    {
        if (r->run == 0)
        {
            uint8_t b;
            if (r->p >= r->end)
                return PCX_ERR_TRUNCATED;
            b = *r->p++;
            if ((b & 0xC0) == 0xC0)
            {
                if (r->p >= r->end)
                    return PCX_ERR_TRUNCATED;
                r->run   = (uint32_t)(b & 0x3F);
                r->value = *r->p++;
                continue;
            }
            r->value = b;
            r->run   = 1;
        }
        {
            size_t c = (size_t)r->run < n ? (size_t)r->run : n;
            memset(dst, r->value, c);
            dst   += c;
            n     -= c;
            r->run -= (uint32_t)c;
        }
    }
    return PCX_OK;
}

/* Unpacks one decoded scanline (planes stored back to back) to 1 byte/pixel indices. */
static inline void pcx__row_indices(const PCXImage *img, const uint8_t *row, uint8_t *out)
{
    const uint32_t w      = img->width;
    const uint32_t bpl    = img->bytes_per_line;
    const unsigned bits   = img->bits_per_plane;
    const unsigned planes = img->planes;
    const unsigned mask   = (1u << bits) - 1u;
    uint32_t x;
    unsigned p;

    if (bits == 8 && planes == 1)
    {
        memcpy(out, row, w);
        return;
    }

    for (x = 0; x < w; x++)
    {
        uint32_t bit   = x * bits;
        uint32_t byte  = bit >> 3;
        unsigned shift = 8u - bits - (unsigned)(bit & 7u);
        unsigned idx   = 0;
        for (p = 0; p < planes; p++)
            idx |= (((unsigned)row[(size_t)p * bpl + byte] >> shift) & mask) << (p * bits);
        out[x] = (uint8_t)idx;
    }
}

static inline const PCXColor *pcx__default_ega(void)
{
    static const PCXColor ega[16] = {
        {  0,   0,   0}, {  0,   0, 170}, {  0, 170,   0}, {  0, 170, 170},
        {170,   0,   0}, {170,   0, 170}, {170,  85,   0}, {170, 170, 170},
        { 85,  85,  85}, { 85,  85, 255}, { 85, 255,  85}, { 85, 255, 255},
        {255,  85,  85}, {255,  85, 255}, {255, 255,  85}, {255, 255, 255}
    };
    return ega;
}

/* ------------------------------------------------------------------------- */
/* Public API                                                                */
/* ------------------------------------------------------------------------- */

static inline const char *pcx_error_string(PCXError e)
{
    switch (e)
    {
    case PCX_OK:               return "ok";
    case PCX_ERR_ARGS:         return "invalid arguments";
    case PCX_ERR_TOO_SMALL:    return "file smaller than PCX header";
    case PCX_ERR_BAD_MAGIC:    return "not a PCX file";
    case PCX_ERR_BAD_ENCODING: return "unknown encoding";
    case PCX_ERR_BAD_HEADER:   return "invalid header fields";
    case PCX_ERR_UNSUPPORTED:  return "unsupported bit depth / plane layout";
    case PCX_ERR_TOO_LARGE:    return "image too large";
    case PCX_ERR_TRUNCATED:    return "pixel data truncated";
    case PCX_ERR_NOMEM:        return "out of memory";
    case PCX_ERR_NOT_INDEXED:  return "image is not indexed";
    }
    return "unknown error";
}

/* Parses and validates the header, locates pixel data and the VGA palette. */
static inline PCXError pcx_parse(const uint8_t *buf, size_t size, PCXImage *img)
{
    int32_t  x0, y0, x1, y1;
    uint32_t w, h, min_bpl;
    unsigned bits, planes;

    if (!buf || !img)
        return PCX_ERR_ARGS;
    memset(img, 0, sizeof(*img));

    if (size < PCX_HEADER_SIZE)
        return PCX_ERR_TOO_SMALL;
    if (buf[0] != 0x0A)
        return PCX_ERR_BAD_MAGIC;
    if (buf[1] > 5)
        return PCX_ERR_BAD_HEADER;
    if (buf[2] > 1)
        return PCX_ERR_BAD_ENCODING;

    bits   = buf[3];
    planes = buf[65];
    if (bits != 1 && bits != 2 && bits != 4 && bits != 8)
        return PCX_ERR_UNSUPPORTED;
    if (planes == 0)
        return PCX_ERR_BAD_HEADER;

    x0 = pcx__s16(buf + 4);
    y0 = pcx__s16(buf + 6);
    x1 = pcx__s16(buf + 8);
    y1 = pcx__s16(buf + 10);
    if (x1 < x0 || y1 < y0)
        return PCX_ERR_BAD_HEADER;
    w = (uint32_t)(x1 - x0) + 1u;
    h = (uint32_t)(y1 - y0) + 1u;

    img->bytes_per_line = pcx__u16(buf + 66);
    min_bpl = (w * bits + 7u) / 8u;
    if (img->bytes_per_line < min_bpl)
        return PCX_ERR_BAD_HEADER;

    if (bits == 8 && planes == 3)
        img->format = PCX_FORMAT_RGB;
    else if (bits == 8 && planes == 4)
        img->format = PCX_FORMAT_RGBA;
    else if (bits * planes <= 8)
    {
        img->format     = PCX_FORMAT_INDEXED;
        img->index_bits = (uint8_t)(bits * planes);
    }
    else
        return PCX_ERR_UNSUPPORTED;

    img->version        = buf[1];
    img->encoding       = buf[2];
    img->bits_per_plane = (uint8_t)bits;
    img->planes         = (uint8_t)planes;
    img->x_min          = x0;
    img->y_min          = y0;
    img->width          = w;
    img->height         = h;
    img->hdpi           = pcx__u16(buf + 12);
    img->vdpi           = pcx__u16(buf + 14);
    img->palette_type   = pcx__u16(buf + 68);
    memcpy(img->header_pal, buf + 16, 48);

    img->data     = buf + PCX_HEADER_SIZE;
    img->data_end = buf + size;

    /* 256-colour palette: 0x0C marker + 768 bytes at the end, version 5 only. */
    if (img->format == PCX_FORMAT_INDEXED && bits == 8 && planes == 1 &&
        img->version == 5 && size >= PCX_HEADER_SIZE + 769 && buf[size - 769] == 0x0C)
    {
        img->vga_pal  = buf + size - 768;
        img->data_end = buf + size - 769;
    }
    return PCX_OK;
}

/* Fills pal[256] for an indexed image. Zeroed for non-indexed images.
 *
 * Source selection:
 *   - 256-colour trailer if present
 *   - 8-bit without trailer: grayscale ramp
 *   - 1 bit, 1 plane: 0 = black, 1 = white (header palette is unreliable here)
 *   - version 0 / 3, or an all-zero header palette: default EGA (>= 3 index bits),
 *     grayscale ramp (2 index bits)
 *   - otherwise: 16-entry header palette. If every byte has only its top two bits
 *     set (EGA 2-bit levels) the values are expanded to 0/85/170/255. */
static inline void pcx_palette(const PCXImage *img, PCXColor pal[256])
{
    unsigned i;
    memset(pal, 0, 256 * sizeof(PCXColor));
    if (!img || img->format != PCX_FORMAT_INDEXED)
        return;

    if (img->vga_pal)
    {
        for (i = 0; i < 256; i++)
        {
            pal[i].r = img->vga_pal[i * 3 + 0];
            pal[i].g = img->vga_pal[i * 3 + 1];
            pal[i].b = img->vga_pal[i * 3 + 2];
        }
        return;
    }

    if (img->index_bits == 1)
    {
        pal[1].r = pal[1].g = pal[1].b = 255;
        return;
    }

    {
        unsigned n = 1u << img->index_bits;
        int any = 0, low_bits = 0, use_default;

        for (i = 0; i < 48; i++)
        {
            if (img->header_pal[i])           any = 1;
            if (img->header_pal[i] & 0x3F)    low_bits = 1;
        }
        use_default = (img->version == 0 || img->version == 3 || !any);

        if (img->index_bits == 8 || (use_default && img->index_bits < 3))
        {
            for (i = 0; i < n; i++)
                pal[i].r = pal[i].g = pal[i].b = (uint8_t)((i * 255u) / (n - 1u));
        }
        else if (use_default)
        {
            const PCXColor *ega = pcx__default_ega();
            for (i = 0; i < 16 && i < n; i++)
                pal[i] = ega[i];
        }
        else
        {
            for (i = 0; i < 16 && i < n; i++)
            {
                uint8_t r = img->header_pal[i * 3 + 0];
                uint8_t g = img->header_pal[i * 3 + 1];
                uint8_t b = img->header_pal[i * 3 + 2];
                if (!low_bits)
                {
                    r = (uint8_t)((r >> 6) * 85);
                    g = (uint8_t)((g >> 6) * 85);
                    b = (uint8_t)((b >> 6) * 85);
                }
                pal[i].r = r;
                pal[i].g = g;
                pal[i].b = b;
            }
        }
    }
}

/* Bytes required for pcx_decode_rgba output, 0 on invalid image or overflow. */
static inline size_t pcx_rgba_size(const PCXImage *img)
{
    if (!img || !img->width || !img->height)
        return 0;
    if ((size_t)img->width > SIZE_MAX / 4 / (size_t)img->height)
        return 0;
    return (size_t)img->width * (size_t)img->height * 4u;
}

/* Decodes an indexed image to width*height palette indices (no row padding).
 * palette may be NULL. */
static inline PCXError pcx_decode_indexed(const PCXImage *img, uint8_t *indices, PCXColor *palette)
{
    PCXReader rd;
    uint8_t  *row;
    uint32_t  y;
    PCXError  err = PCX_OK;
    size_t    rb;

    if (!img || !indices)
        return PCX_ERR_ARGS;
    if (img->format != PCX_FORMAT_INDEXED)
        return PCX_ERR_NOT_INDEXED;

    rb  = pcx__row_bytes(img);
    row = (uint8_t *)PCX_MALLOC(rb);
    if (!row)
        return PCX_ERR_NOMEM;

    pcx__reader_init(&rd, img);
    for (y = 0; y < img->height; y++)
    {
        err = pcx__read_row(&rd, row, rb);
        if (err != PCX_OK)
            break;
        pcx__row_indices(img, row, indices + (size_t)y * img->width);
    }
    PCX_FREE(row);

    if (err == PCX_OK && palette)
        pcx_palette(img, palette);
    return err;
}

/* Decodes any supported image to RGBA8, top-down, width*height*4 bytes
 * (see pcx_rgba_size). Alpha is 255 except for 4-plane truecolor. */
static inline PCXError pcx_decode_rgba(const PCXImage *img, uint8_t *out)
{
    PCXReader rd;
    PCXColor  pal[256];
    uint8_t  *scratch, *row, *idx;
    uint32_t  x, y;
    PCXError  err = PCX_OK;
    size_t    rb, extra;

    if (!img || !out)
        return PCX_ERR_ARGS;
    if (!pcx_rgba_size(img))
        return PCX_ERR_TOO_LARGE;

    rb    = pcx__row_bytes(img);
    extra = (img->format == PCX_FORMAT_INDEXED) ? img->width : 0;
    scratch = (uint8_t *)PCX_MALLOC(rb + extra);
    if (!scratch)
        return PCX_ERR_NOMEM;
    row = scratch;
    idx = scratch + rb;

    if (img->format == PCX_FORMAT_INDEXED)
        pcx_palette(img, pal);

    pcx__reader_init(&rd, img);
    for (y = 0; y < img->height && err == PCX_OK; y++)
    {
        uint8_t *dst = out + (size_t)y * img->width * 4u;
        const size_t bpl = img->bytes_per_line;

        err = pcx__read_row(&rd, row, rb);
        if (err != PCX_OK)
            break;

        if (img->format == PCX_FORMAT_INDEXED)
        {
            pcx__row_indices(img, row, idx);
            for (x = 0; x < img->width; x++)
            {
                const PCXColor *c = &pal[idx[x]];
                dst[x * 4 + 0] = c->r;
                dst[x * 4 + 1] = c->g;
                dst[x * 4 + 2] = c->b;
                dst[x * 4 + 3] = 255;
            }
        }
        else
        {
            const int has_a = (img->format == PCX_FORMAT_RGBA);
            for (x = 0; x < img->width; x++)
            {
                dst[x * 4 + 0] = row[x];
                dst[x * 4 + 1] = row[bpl + x];
                dst[x * 4 + 2] = row[bpl * 2 + x];
                dst[x * 4 + 3] = has_a ? row[bpl * 3 + x] : 255;
            }
        }
    }
    PCX_FREE(scratch);
    return err;
}

/* One-call convenience. Returns malloc'd RGBA8 (free with pcx_free) or NULL. */
static inline uint8_t *pcx_load_rgba(const uint8_t *buf, size_t size,
                                     uint32_t *w, uint32_t *h, PCXError *err_out)
{
    PCXImage img;
    uint8_t *out = NULL;
    PCXError err = pcx_parse(buf, size, &img);

    if (err == PCX_OK)
    {
        size_t n = pcx_rgba_size(&img);
        if (!n)
            err = PCX_ERR_TOO_LARGE;
        else if (!(out = (uint8_t *)PCX_MALLOC(n)))
            err = PCX_ERR_NOMEM;
        else if ((err = pcx_decode_rgba(&img, out)) != PCX_OK)
        {
            PCX_FREE(out);
            out = NULL;
        }
    }
    if (err == PCX_OK)
    {
        if (w) *w = img.width;
        if (h) *h = img.height;
    }
    if (err_out)
        *err_out = err;
    return out;
}

static inline void pcx_free(void *p)
{
    PCX_FREE(p);
}

#ifdef __cplusplus
}
#endif

#endif /* PCX_H */
