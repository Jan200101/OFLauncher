#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <dirent.h>

#ifdef _WIN32
#include "windows.h"
#endif

#include "config.h"
#include "steam.h"
#include "common.h"

int runMod(char* modpath)
{
    char steam[PATH_MAX];
    getSteamPath(steam, sizeof(steam));

    strncat(steam, STEAM_BIN, sizeof(steam) - strlen(steam) - 1);

    char modexec[PATH_MAX*2]; // lets be sure for now
    snprintf(modexec, sizeof(modexec), "%s -applaunch %s -game %s -secure -steam", steam, STEAM_APPID, modpath);

    return system(modexec);
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
#elif _WIN32
    #warning TODO
#endif
    return 0;

}



// https://stackoverflow.com/questions/39066998/what-are-the-meaning-of-values-at-proc-pid-stat#39067246
bool isSteamRunning()
{
#ifdef __linux__

    long pid;
    char buf[PATH_MAX];
    struct dirent* ent;
    DIR* proc = opendir("/proc");
    FILE* stat;

    if (proc)
    {
        while ((ent = readdir(proc)) != NULL)
        {
            long lpid = atol(ent->d_name);
            if (!lpid) continue;

            snprintf(buf, sizeof(buf), "/proc/%ld/stat", lpid);
            stat = fopen(buf, "r");

            if (stat && (fscanf(stat, "%li (%[^)])", &pid, buf)) == 2)
            {                
                if (!strcmp(buf, STEAM_PROC))
                {
                    fclose(stat);
                    closedir(proc);
                    return true;
                }
                fclose(stat);
            }
        }

        closedir(proc);
    }

#elif _WIN32
    #warning TODO
#endif
    return false;
}