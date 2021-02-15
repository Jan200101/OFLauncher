#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "svn.h"
#include "common.h"

#ifdef _WIN32
const char SVN_BINS[SVN_MAX][255] = {
    "\\Subversion\\bin\\svn.exe",
    "\\TortoiseSVN\\bin\\svn.exe"
};

char SVN[PATH_MAX] = {0};
#endif

int svn_init()
{
#ifdef _WIN32
    strcpy(SVN, PGRM32);
    for (int i = 0; i < SVN_MAX; ++i)
    {
        strcpy(SVN+strlen(PGRM32), SVN_BINS[i]);
        if (isFile(SVN)) return 0;
    }

    IF_WIN64
    {
        strcpy(SVN, PGRM64);
        for (int i = 0; i < SVN_MAX; ++i)
        {
            strcpy(SVN+strlen(PGRM64), SVN_BINS[i]);
            if (isFile(SVN)) return 0;
        }
    }

    return 1;
#else
    return !isFile(SVN);
#endif
}

int svn_checkout(char* path, char* url)
{
    char exec[PATH_MAX] = {0};
    strcpy(exec, "\"");
#ifdef _WIN32
    strcat(exec, "\"");
#endif
    strcat(exec, SVN);
    strcat(exec, "\" " SVN_CHECKOUT " \"");
    strcat(exec, url);
    strcat(exec, "\" \"");
    strcat(exec, path);
    strcat(exec, "\"");
#ifdef _WIN32
    strcat(exec, "\"");
#endif

    return system(exec);
}

int svn_update(char* path)
{
    char exec[PATH_MAX] = {0};
    strcpy(exec, "\"");
#ifdef _WIN32
    strcat(exec, "\"");
#endif
    strcat(exec, SVN);
    strcat(exec, "\" " SVN_UPDATE " \"");
    strcat(exec, path);
    strcat(exec, "\"");
#ifdef _WIN32
    strcat(exec, "\"");
#endif

    return system(exec);
}

int svn_delete(char* path)
{
    return removeDir(path);
}