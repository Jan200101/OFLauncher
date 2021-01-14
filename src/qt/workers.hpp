#ifndef WORKERS_HPP
#define WORKERS_HPP

#include <QObject>

class svnWorker : public QObject
{
    Q_OBJECT

public:
    enum svnTasks
    {
        SVN_INSTALL,
        SVN_UPDATE,
        SVN_DELETE,
    };
    Q_ENUM(svnTasks)

    enum svnResults
    {
        SVN_UNKNOWN,
        SVN_BAD_PATH,
        SVN_GOOD
    };
    Q_ENUM(svnResults)

public slots:
    void doWork(const svnTasks &);

signals:
    void resultReady(const svnResults &);

};


#endif