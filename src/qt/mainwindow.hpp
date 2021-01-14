#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QThread>
#include <QMainWindow>

#include "settings.hpp"
#include "workers.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void handleSVN(const svnWorker::svnResults &);
    void settingsWindow();
    void enable();
    void install();

signals:
    void operateSVN(const svnWorker::svnTasks &);

private:
    Ui::MainWindow *ui;
    Settings* settings;
    QThread thread;
};
#endif // MAINWINDOW_HPP
