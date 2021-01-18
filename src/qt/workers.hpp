#ifndef WORKERS_HPP
#define WORKERS_HPP

#include <QObject>
#include <limits.h>

#include "svn.h"

class Worker : public QObject
{
    Q_OBJECT

private:
    char mod[PATH_MAX];
    size_t modlen;

    char url[PATH_MAX];
    size_t urllen;

public:
    Worker();

    enum Tasks_t
    {
        TASK_INVALID,

        TASK_IS_FOLDER,

        TASK_INSTALL,
        TASK_UNINSTALL,
        TASK_UPDATE,
        TASK_UPDATE_RUN,
        TASK_RUN,
    };
    Q_ENUM(Tasks_t)

    enum Results_t
    {
        RESULT_NONE,
        RESULT_EXIT,

        RESULT_FOLDER_EXISTS,
        RESULT_FOLDER_MISSING,

        RESULT_INSTALL_COMPLETE,
        RESULT_UNINSTALL_COMPLETE,
        RESULT_UPDATE_COMPLETE,
        RESULT_UPDATE_RUN,

        RESULT_FAILURE, // TODO make specific FAILURE for each results

        RESULT_NO_STEAM
    };
    Q_ENUM(Results_t)

public slots:
    void doWork(const Tasks_t &);

signals:
    void resultReady(const Results_t &);

};


#endif