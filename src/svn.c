#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "svn.h"
#include "common.h"

int svn_check()
{
    return !isFile(SVN);
}

int svn_checkout(char* path, char* url)
{
    char exec[PATH_MAX] = {0};
    strcpy(exec, SVN " " SVN_CHECKOUT " ");
    strcat(exec, url);
    strcat(exec, " ");
    strcat(exec, path);

    return system(exec);
}

int svn_update(char* path)
{
    char exec[PATH_MAX] = {0};
    strcpy(exec, SVN " " SVN_UPDATE " ");
    strcat(exec, path);

    return system(exec);
}

int svn_delete(char* path)
{
    return removeDir(path);
}