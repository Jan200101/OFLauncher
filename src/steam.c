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
#include <windows.h>
#include <tlhelp32.h>
#endif

#include "config.h"
#include "steam.h"
#include "common.h"

size_t getSteamPath(char* buf, size_t size)
{
    size_t retval = 0;
#ifdef __linux__
    char* home = getenv("HOME");

    if (home && isDir(home))
    {
        // create a buffer to try out paths
        char path[size+1];
        path[0] = '\0';
        strncpy(path, home, sizeof(path) - 1);
        strncat(path, STEAM_DIR, sizeof(path) - strlen(path) - 1);

        if (isDir(path))
        {
            retval = size+1;
            if (size < retval) retval = size;
            strncpy(buf, path, size-1);
            return retval;
        }

        path[strlen(home) + 2] = '\0';
        strncat(path, FLATPAK_DIR, sizeof(path) - strlen(path) - 1);

        if (isDir(path))
        {
            retval = size+1;
            if (size < retval) retval = size;
            strncpy(buf, path, size-1);
            return retval;
        }
    }
#elif _WIN32
    char path[size+1];
    char* fallbackdir = FALLBACK32_DIR;
    IF_WIN64 fallbackdir = FALLBACK64_DIR;
    LSTATUS res = RegGetValueA(HKEY_LOCAL_MACHINE, REG_PATH, "InstallPath", RRF_RT_REG_SZ, NULL, &path, (LPDWORD)&size);

    if (res == ERROR_SUCCESS && isDir(path))
    {
        retval = size+1;
        if (size < retval) retval = size;
        strncpy(buf, path, size);
        return retval;
    }
    else if (isDir(fallbackdir))
    {
        retval = strlen(fallbackdir) + 1;
        if (size < retval) retval = size;
        strncpy(buf, fallbackdir, size);
        return retval;
    }

#else
    #error No Implementation
#endif
    return 0;

}


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
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32 = {0};
    pe32.dwSize = sizeof(PROCESSENTRY32); 
    Process32First(hSnap,&pe32); // Can throw away, never an actual app

    while(Process32Next(hSnap,&pe32))
    {
        if (strcmp(pe32.szExeFile, STEAM_PROC) == 0) // Did we find our process?
        {
            return true;
        }
    }
#else
    #error No Implementation
#endif
    return false;
}