#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps, true);
    w.show();

    return a.exec();
}
