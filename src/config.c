#include <string.h>
#include <limits.h>

#include "config.h"
#include "steam.h"

size_t getRepoURL(char* buf, size_t size)
{
    char* repo_url = DEFAULT_REPO;

    size_t retval = strlen(repo_url)+1;
    if (size < retval) retval = size;

    strncpy(buf, repo_url, size);
    return retval;
}

size_t getRepoName(char* buf, size_t size)
{
    char* repo_url = DEFAULT_NAME;

    size_t retval = strlen(repo_url)+1;
    if (size < retval) retval = size;

    strncpy(buf, repo_url, size);
    return retval;
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