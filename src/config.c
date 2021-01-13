#include <string.h>

#include "config.h"

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