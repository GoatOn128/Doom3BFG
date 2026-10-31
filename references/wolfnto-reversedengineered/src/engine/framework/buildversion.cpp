#include "engine/framework/buildversion.h"

#include "engine/decls/decl.h"
#include "shared/idlib/lib.h"

namespace {
constexpr const char* GAME_NAME = "Wolfenstein The New Order";
constexpr int BUILD_NUMBER = 1683;
constexpr int BUILD_NUMBER_MINOR = 12143;
constexpr const char* BUILD_SUFFIX = "";
constexpr const char* BUILD_TARGET = "win-x64";
constexpr const char* BUILD_CONFIG = "Retail";
constexpr const char* BUILD_EXTRA = "";
constexpr const char* BUILD_DATE = "May 18 2014";
constexpr const char* BUILD_TIME = "15:23:39";
} // namespace

idVersionInfo::idVersionInfo() {
  idStr::snPrintf(fullVersion, sizeof(fullVersion),
                  "%s.%d.%d%s %s %s %s %s %s", GAME_NAME, BUILD_NUMBER,
                  BUILD_NUMBER_MINOR, BUILD_SUFFIX, BUILD_TARGET, BUILD_CONFIG,
                  BUILD_EXTRA, BUILD_DATE, BUILD_TIME);
  idStr::snPrintf(netVersion, sizeof(netVersion), "%s.%d.%d%s", GAME_NAME,
                  BUILD_NUMBER, BUILD_NUMBER_MINOR, BUILD_SUFFIX);
}

idEngineVersionInfo::idEngineVersionInfo()
    : versionName("engine"), buildName("developer"), buildType(""),
      buildDescription("developer"), compileTarget(""), buildURL(""),
      requestor(""), mostRelevantChangelistsDisplay(""), fullVersion(),
      automated(false), ciGenerated(false) {
  fullVersion.Format("%d.%d.%d", 5, 1, 1);
}

bool idEngineVersionInfo::IsForgedBuild() const {
  return idStr::Cmp(forge_buildBinType.GetString(), "forged") == 0;
}

idStr idBuildVersionInfo::GetBinaryDesc() const {
  const char* const type = forge_buildBinType.GetString();
  const char* const name = forge_buildBinName.GetString();

  if (!engineVersionInfo.automated) {
    if (idStr::Cmp(type, "forged") == 0) {
      return idStr(va("(forced forged) %s ", name));
    }
    if (idStr::Cmp(type, "developer") == 0) {
      return idStr(va("Developer Binary - %s %s ", BUILD_DATE, BUILD_TIME));
    }
    if (idStr::Cmp(type, "uploaded") == 0) {
      return idStr(va("Uploaded %s ", name));
    }
    return idStr(va("(%s) %s ", type, name));
  }

  if (idStr::Cmp(type, "forged") == 0) {
    return idStr(name);
  }
  return idStr(va("(forced %s) %s ", type, name));
}

idStr idBuildVersionInfo::GetPackageDesc() const {
  if (idLib::production != PROD_PRODUCTION &&
      idLib::production != PROD_LOADED) {
    return idStr("Loose Assets ");
  }

  const char* const type = forge_buildPkgType.GetString();
  const char* const name = forge_buildPkgName.GetString();
  if (idStr::Cmp(type, "developer") == 0) {
    return idStr("Developer Package ");
  }
  if (idStr::Cmp(type, "uploaded") == 0) {
    return idStr(va("Uploaded %s ", name));
  }
  if (idStr::Cmp(type, "forged") == 0) {
    return idStr(va("%s ", name));
  }
  return idStr(va("(%s) %s ", type, name));
}

idStr idBuildVersionInfo::GetComponentDetails() const {
  const char* const binary = forge_buildBinRelevantChangelists.GetString();
  if (idLib::production == PROD_PRODUCTION ||
      idLib::production == PROD_LOADED) {
    return idStr(va("C %s : A %s ", binary,
                    forge_buildPkgRelevantChangelists.GetString()));
  }
  if (idLib::production == PROD_DEVELOPMENT) {
    return idStr(va("C %s : A loose ", binary));
  }
  return idStr(va("C %s : A unknown ", binary));
}

idVersionInfo versionInfo;
idCVar com_version("com_version", versionInfo.fullVersion, CVAR_ROM,
                   "engine version");
idCVar net_version("net_version", versionInfo.netVersion, CVAR_ROM,
                   "network version");

idEngineVersionInfo engineVersionInfo;
idCVar forge_buildBinVersion("forge_buildBinVersion",
                             engineVersionInfo.fullVersion.data, CVAR_ROM,
                             "binary build version");
idCVar forge_buildBinName("forge_buildBinName", engineVersionInfo.buildName,
                          0, "forge binary build name");
idCVar forge_buildBinRelevantChangelists(
    "forge_buildBinRelevantChangelists",
    engineVersionInfo.mostRelevantChangelistsDisplay, CVAR_ROM,
    "binary relevant Perforce changelists");
idCVar forge_buildBinURL("forge_buildBinURL", engineVersionInfo.buildURL, 0,
                         "forge binary build url");
idCVar forge_buildBinRequestor("forge_buildBinRequestor",
                               engineVersionInfo.requestor, 0,
                               "forge binary build requestor");
idCVar forge_buildBinType("forge_buildBinType", engineVersionInfo.buildType, 0,
                          "forge binary build type");

idCVar forge_buildPkgName("forge_buildPkgName", "", 0,
                          "forge package build name");
idCVar forge_buildPkgMapSet("forge_buildPkgMapSet", "", 0,
                            "forge package map set");
idCVar forge_buildPkgRelevantChangelists(
    "forge_buildPkgRelevantChangelists", "unknown", 0,
    "package relevant Perforce changelists");
idCVar forge_buildPkgURL("forge_buildPkgURL", "", 0,
                         "forge package build url");
idCVar forge_buildPkgRequestor("forge_buildPkgRequestor", "", 0,
                               "forge package build requestor");
idCVar forge_buildPkgType("forge_buildPkgType", "developer", 0,
                          "forge package build type");

idBuildVersionInfo buildVersionInfo;
