#include <iostream>
#include <limits.h>

#include "steam.h"
#include "workers.hpp"

Worker::Worker()
{
    modlen = getModPath(mod, sizeof(mod));
}

void Worker::doWork(const enum Worker::Tasks_t &parameter) {
    Results_t result = RESULT_NONE;

    if (modlen)
    {
        switch (parameter)
        {
            case TASK_IS_FOLDER:
                result = RESULT_FOLDER_EXISTS;
                break;

            case TASK_UPDATE:
                svn_update(mod);
                break;

            case TASK_UPDATE_RUN:
                svn_update(mod);
                result = RESULT_UPDATE_RUN;
                break;

            case TASK_RUN:
                runMod(mod);
                result = RESULT_EXIT;
                std::cout << "RUN" << std::endl;
                break;
        }
    }
    else
    {
        result = RESULT_FOLDER_MISSING;
    }

    emit resultReady(result);
}