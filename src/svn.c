#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <svn_cmdline.h>
#include <svn_client.h>
#include <svn_pools.h>
#include <svn_opt.h>
#include <svn_fs.h>

#include "svn.h"
#include "common.h"

// a bunch of svn functions in here are deprecated
// we do not care
// they are simpler to use and supported on older systems
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

apr_pool_t *pool;
svn_opt_revision_t rev;
svn_client_ctx_t *ctx;
svn_error_t *err;

inline int handle_error()
{
    if (err)
    {
        svn_handle_error2 (err, stderr, FALSE, NAME ": ");
        return 1;
    }

    return 0;
}

int svn_init()
{
    svn_cmdline_init(NAME, stderr);

    pool = svn_pool_create(NULL);
    err = svn_fs_initialize(pool); // TODO check error
    if (handle_error()) return 1;

    rev.kind = svn_opt_revision_head;

    err = svn_config_ensure(NULL, pool);
    if (handle_error()) return 1;
    err = svn_client_create_context(&ctx, pool);
    if (handle_error()) return 1;
    err = svn_config_get_config(&(ctx->config), NULL, pool);
    if (handle_error()) return 1;

    return 0;   
}

int svn_checkout(char* path, char* url)
{
    err = svn_client_checkout(NULL, url, path, &rev, true, ctx, pool);

    return handle_error();
}

int svn_update(char* path)
{
    svn_revnum_t tmp;

    err = svn_client_update(&tmp, path, &rev, true, ctx, pool);

    return handle_error();
}

int svn_delete(char* path)
{
    return removeDir(path);
}