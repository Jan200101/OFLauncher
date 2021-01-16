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

private:
    Ui::MainWindow *ui;
    Settings* settings;
    QThread thread;
    bool installed;

public slots:
    void workerResult(const Worker::Results_t &);

private slots:
    void settingsWindow();
    void setupButton();
    void handleButton();

signals:
    void workerOperate(const Worker::Tasks_t &);

};
#endif // MAINWINDOW_HPP
