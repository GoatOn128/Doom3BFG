#pragma once

#include "shared/idlib/csystems/cvarsystemlocal.h"
#include "shared/idlib/text/str.h"

#include <cstddef>

class idVersionInfo {
public:
  idVersionInfo();

  const char* GetFullVersion() const { return fullVersion; }
  const char* GetNetVersion() const { return netVersion; }

  char fullVersion[128];
  char netVersion[128];
};

class idBaseVersionInfo {
public:
  virtual const char* GetVersionName() const = 0;
  virtual const char* GetFullVersion() const = 0;
  virtual int GetMajorVersion() const = 0;
  virtual int GetMinorVersion() const = 0;
  virtual int GetComponentVersion() const = 0;
  virtual ~idBaseVersionInfo() = default;
};

class idEngineVersionInfo final : public idBaseVersionInfo {
public:
  idEngineVersionInfo();

  const char* GetVersionName() const override { return versionName; }
  const char* GetFullVersion() const override { return fullVersion.data; }
  int GetMajorVersion() const override { return 5; }
  int GetMinorVersion() const override { return 1; }
  int GetComponentVersion() const override { return 1; }

  const char* GetBuildName() const { return buildName; }
  const char* GetBuildType() const { return buildType; }
  const char* GetBuildDescription() const { return buildDescription; }
  const char* GetCompileTarget() const { return compileTarget; }
  const char* GetBuildURL() const { return buildURL; }
  const char* GetRequestor() const { return requestor; }
  const char* GetMostRelevantChangelistsDisplay() const {
    return mostRelevantChangelistsDisplay;
  }
  bool IsAutomated() const { return automated; }
  bool IsCIGenerated() const { return ciGenerated; }
  const char* GetBuildDate() const { return "May 18 2014"; }
  const char* GetBuildTime() const { return "15:23:39"; }
  bool IsForgedBuild() const;

  const char* const versionName;
  const char* const buildName;
  const char* const buildType;
  const char* const buildDescription;
  const char* const compileTarget;
  const char* const buildURL;
  const char* const requestor;
  const char* const mostRelevantChangelistsDisplay;
  idStr fullVersion;
  bool automated;
  bool ciGenerated;
};

class idBuildVersionInfo {
public:
  idStr GetBinaryDesc() const;
  idStr GetPackageDesc() const;
  idStr GetComponentDetails() const;
};

extern idVersionInfo versionInfo;
extern idEngineVersionInfo engineVersionInfo;
extern idBuildVersionInfo buildVersionInfo;

extern idCVar com_version;
extern idCVar net_version;
extern idCVar forge_buildBinVersion;
extern idCVar forge_buildBinName;
extern idCVar forge_buildBinRelevantChangelists;
extern idCVar forge_buildBinURL;
extern idCVar forge_buildBinRequestor;
extern idCVar forge_buildBinType;
extern idCVar forge_buildPkgName;
extern idCVar forge_buildPkgMapSet;
extern idCVar forge_buildPkgRelevantChangelists;
extern idCVar forge_buildPkgURL;
extern idCVar forge_buildPkgRequestor;
extern idCVar forge_buildPkgType;

static_assert(sizeof(idVersionInfo) == 0x100, "idVersionInfo ABI drift");
static_assert(sizeof(idBaseVersionInfo) == 0x08,
              "idBaseVersionInfo ABI drift");
static_assert(sizeof(idEngineVersionInfo) == 0x78,
              "idEngineVersionInfo ABI drift");
static_assert(offsetof(idEngineVersionInfo, versionName) == 0x08,
              "idEngineVersionInfo::versionName ABI drift");
static_assert(offsetof(idEngineVersionInfo, fullVersion) == 0x48,
              "idEngineVersionInfo::fullVersion ABI drift");
static_assert(offsetof(idEngineVersionInfo, automated) == 0x70,
              "idEngineVersionInfo::automated ABI drift");

