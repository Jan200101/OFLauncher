#include <iostream>
#include <limits.h>

#include "common.h"
#include "config.h"
#include "steam.h"
#include "workers.hpp"

Worker::Worker()
{
    modlen = getModPath(mod, sizeof(mod));
    urllen = getRepoURL(url, sizeof(url));
}

void Worker::doWork(const enum Worker::Tasks_t &parameter) {
    Results_t result = RESULT_NONE;

    bool direxists = isDir(mod);

    if (modlen && (direxists || parameter == TASK_INSTALL))
    {
        switch (parameter)
        {
            case TASK_INVALID:
                break;

            case TASK_INIT:
                result = svn_init() ? RESULT_INIT_FAILURE : RESULT_INIT_COMPLETE;
                break;

            case TASK_IS_FOLDER:
                result = RESULT_FOLDER_EXISTS;
                break;

            case TASK_UNINSTALL:
                if (direxists) result = svn_delete(mod) ? RESULT_UNINSTALL_FAILURE : RESULT_UNINSTALL_COMPLETE;
                break;

            case TASK_INSTALL:
                if (!direxists) result = svn_checkout(mod, url) ? RESULT_INSTALL_FAILURE : RESULT_INSTALL_COMPLETE;
                break;

            case TASK_UPDATE:
                if (direxists) result = svn_update(mod) ? RESULT_UPDATE_FAILURE : RESULT_UPDATE_COMPLETE;
                result = RESULT_UPDATE_COMPLETE;
                break;

            case TASK_UPDATE_RUN:
                if (direxists) result = svn_update(mod) ? RESULT_UPDATE_FAILURE : RESULT_UPDATE_RUN;
                break;

            case TASK_RUN:
                result = isSteamRunning() ? RESULT_EXIT : RESULT_NO_STEAM; 
                if (result == RESULT_EXIT) runMod(mod);
                break;
        }
    }
    else
    {
        result = RESULT_FOLDER_MISSING;
    }

    emit resultReady(result);
}