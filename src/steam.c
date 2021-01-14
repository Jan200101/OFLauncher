#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#include "config.h"
#include "steam.h"
#include "common.h"

int runMod(char* modpath, size_t size UNUSED)
{
    char steam[PATH_MAX];
    getSteamPath(steam, sizeof(steam));

    strncat(steam, STEAM_BIN, sizeof(steam) - strlen(steam) - 1);

    return execl(steam, steam, "-applaunch", STEAM_APPID, "-game", modpath, "-secure", "-steam", NULL);
}

size_t getModPath(char* buf, size_t size)
{
    char steam[PATH_MAX];
    if (!getSteamPath(steam, sizeof(steam)))
        return 0;

    char name[PATH_MAX];
    getRepoName(name, sizeof(name));

    strncat(steam, MOD_DIR, sizeof(steam) - strlen(steam) - 1);
    strncat(steam, name, sizeof(steam) - strlen(steam) - 1);

    strncpy(buf, steam, size-1);

    size_t retval = strlen(steam)+1;
    if (size < retval) retval = size;

    return retval;
}

size_t getSteamPath(char* buf, size_t size)
{
#ifdef __linux__
    char* home = getenv("HOME");
    size_t retval = 0;

    if (home && isDir(home))
    {
        // create a buffer to try out paths
        char path[PATH_MAX] = {0};
        strncpy(path, home, sizeof(path) - 1);
        strncat(path, "/", sizeof(path) - strlen(path) - 1);
        strncat(path, STEAM_DIR, sizeof(path) - strlen(path) - 1);

        if (isDir(path))
        {
            retval = strlen(path)+1;
            if (size < retval) retval = size;
            strncpy(buf, path, size-1);
            return retval;
        }

        path[strlen(home) + 2] = '\0';
        strncpy(path, FLATPAK_DIR, sizeof(path) - strlen(path) - 1);

        if (isDir(path))
        {
            retval = strlen(path)+1;
            if (size < retval) retval = size;
            strncpy(buf, path, size-1);
            return retval;
        }
    }
#endif
    return 0;

}