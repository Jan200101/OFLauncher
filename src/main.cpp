#include "oflauncher.hpp"
//#include "phantomstyle.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    OFLauncher w;
    //QApplication::setStyle(new PhantomStyle);
    w.show();

    return a.exec();
}
