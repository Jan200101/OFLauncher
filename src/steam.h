#ifndef STEAM_H
#define STEAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include "common.h"

#ifdef _WIN32
#define STEAM_PROC "steam.exe"
#define STEAM_BIN "\\" STEAM_PROC
#else
#define STEAM_PROC "steam"
#define STEAM_BIN "steam.sh"
#endif

#define STEAM_APPID "243750"

#ifdef _WIN32
#define FALLBACK64_DIR PGRM64 "\\Steam"
#define FALLBACK32_DIR PGRM32 "\\Steam"
#define MOD_DIR "\\steamapps\\sourcemods\\"
// TODO check if this is the right registry path for x86
#define REG_PATH "SOFTWARE\\Wow6432Node\\Valve\\Steam"
#else // _WIN32
#define MOD_DIR "steamapps/sourcemods/"
#define STEAM_DIR "/.local/share/Steam/"
#define FLATPAK_DIR "/.var/app/com.valvesoftware.Steam" STEAM_DIR
#endif

size_t getSteamPath(char*, size_t);
bool isSteamRunning();

#ifdef __cplusplus
}
#endif

#endif