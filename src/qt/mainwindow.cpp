#include <QApplication>
#include <QFontDatabase>

#include <limits.h>

#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "workers.hpp"

#include "common.h"
#include "steam.h"

#define FONT "TF2Build"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);

    qRegisterMetaType<Worker::Tasks_t>("Task_t");
    qRegisterMetaType<Worker::Results_t>("Results_t");

    QFontDatabase::addApplicationFont (":/fonts/res/" FONT ".ttf");
    QFont playFont(FONT, 20, QFont::Bold);
    QFont progressFont(FONT, 10, QFont::Normal);

    ui->playButton->setFont(playFont);
    ui->status->setFont(progressFont);

    QPixmap bkgnd(":/images/res/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    Worker* th = new Worker;
    th->moveToThread(&thread);

    connect(&thread, &QThread::finished, th, &QObject::deleteLater);
    connect(this, &MainWindow::workerOperate, th, &Worker::doWork);
    connect(th, &Worker::resultReady, this, &MainWindow::workerResult);

    thread.start();

    //operateSVN(svnWorker::SVN_INSTALL);

    connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(settingsWindow()));

    settings = new Settings(this);
    settings->setModal(false);
    //connect(settings, SIGNAL(visibleChanged()), this, SLOT(enable()));

    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(handleButton()));


    setupButton();

}

void MainWindow::workerResult(const enum Worker::Results_t &result)
{
    switch (result)
    {
        case Worker::RESULT_NONE:
            break;

        case Worker::RESULT_EXIT:
            QCoreApplication::quit();
            break;

        case Worker::RESULT_FOLDER_EXISTS:
            ui->playButton->setText("Play");
            installed = true;
            break;

        case Worker::RESULT_FOLDER_MISSING:
            ui->playButton->setText("Install");
            installed = false;
            break;

        case Worker::RESULT_UPDATE_RUN:
            workerOperate(Worker::TASK_RUN);
            break;
    }
}

void MainWindow::settingsWindow()
{
    settings->show();
    //this->setEnabled(false);
}

void MainWindow::setupButton()
{
    workerOperate(Worker::TASK_IS_FOLDER);
}

void MainWindow::handleButton()
{
    if (installed)
    {
        workerOperate(Worker::TASK_UPDATE_RUN);
    }
    else
    {
        workerOperate(Worker::TASK_INSTALL);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settings;

    thread.quit();
    thread.wait();
}

