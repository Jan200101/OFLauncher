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

            case TASK_IS_FOLDER:
                result = RESULT_FOLDER_EXISTS;
                break;

            case TASK_UNINSTALL:
                if (direxists) svn_delete(mod);
                result = RESULT_UNINSTALL_COMPLETE;
                break;

            case TASK_INSTALL:
                if (!direxists) svn_checkout(mod, url);
                result = RESULT_INSTALL_COMPLETE;
                break;

            case TASK_UPDATE:
                if (direxists) svn_update(mod);
                result = RESULT_UPDATE_COMPLETE;
                break;

            case TASK_UPDATE_RUN:
                svn_update(mod);
                result = RESULT_UPDATE_RUN;
                break;

            case TASK_RUN:
                if (isSteamRunning())
                {
                    runMod(mod);
                    result = RESULT_EXIT;
                }
                else
                {
                    result = RESULT_NO_STEAM;
                }
                break;
        }
    }
    else
    {
        result = RESULT_FOLDER_MISSING;
    }

    emit resultReady(result);
}