#ifndef STEAM_H
#define STEAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

#ifdef __linux__
#define STEAM_PROC "steam"
#elif _WIN32
#define STEAM_PROC "steam.exe"
#endif

#define STEAM_BIN "steam.sh"
#define STEAM_APPID "243750"

#define STEAM_DIR ".local/share/Steam/"
#define FLATPAK_DIR ".var/app/com.valvesoftware.Steam/" STEAM_DIR

#define MOD_DIR "steamapps/sourcemods/"

int runMod(char*);
size_t getModPath(char*, size_t);
size_t getSteamPath(char*, size_t);
bool isSteamRunning();

#ifdef __cplusplus
}
#endif

#endif