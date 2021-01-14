#include <iostream>

#include "steam.h"
#include "workers.hpp"

void svnWorker::doWork(const enum svnWorker::svnTasks &parameter) {
    svnResults result;

    char mod[PATH_MAX];
    size_t modsize = getModPath(mod, sizeof(mod));

    if (modsize)
    {
        switch (parameter)
        {
            case SVN_INSTALL:
                std::cout << "SVN_INSTALL" << std::endl;
                break;

            case SVN_UPDATE:
                std::cout << "SVN_UPDATE" << std::endl;
                break;

            case SVN_DELETE:
                std::cout << "SVN_DELETE" << std::endl;
                break;

            default:
                result = SVN_UNKNOWN;
        }
    }
    else
    {
        result = SVN_BAD_PATH;
    }

    emit resultReady(result);
}