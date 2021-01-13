#include <stdlib.h>
#include <unistd.h>

#include "svn.h"
#include "common.h"

int svn_check()
{
    return !isFile(SVN);
}

int svn_checkout(char* path, char* url)
{
    return execl(SVN, SVN, SVN_CHECKOUT, url, path, NULL);
}

int svn_update(char* path)
{
    return execl(SVN, SVN, SVN_UPDATE, path, NULL);
}

int svn_delete(char* path)
{
    return removeDir(path);
}