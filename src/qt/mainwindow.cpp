#include <QApplication>
#include <QMessageBox>
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


    workerOperate(Worker::TASK_INIT);
}

void MainWindow::workerResult(const enum Worker::Results_t &result)
{
    switch (result)
    {

        case Worker::RESULT_UNINSTALL_COMPLETE:
        case Worker::RESULT_UNINSTALL_FAILURE:
        // TODO find better use for these
        case Worker::RESULT_NONE:
            resetProgress();
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

        case Worker::RESULT_INIT_COMPLETE:
            setupButton();
            break;

        case Worker::RESULT_INIT_FAILURE:
            QMessageBox::information(this, windowTitle(), "Could not find a SVN binary");
            QCoreApplication::quit();
            break;

        case Worker::RESULT_INSTALL_COMPLETE:
            ui->status->setFormat("Installed");
            ui->status->setValue(100);
            setupButton();
            break;

        case Worker::RESULT_INSTALL_FAILURE:
            ui->status->setFormat("Install failed");
            ui->status->setValue(100);
            break;

        case Worker::RESULT_UPDATE_COMPLETE:
            ui->status->setFormat("Updated");
            ui->status->setValue(100);
            break;

        case Worker::RESULT_UPDATE_RUN:
            ui->status->setFormat("Launching");
            ui->status->setValue(66);
            workerOperate(Worker::TASK_RUN);
            break;

        case Worker::RESULT_UPDATE_FAILURE:
            ui->status->setFormat("Update failed");
            ui->status->setValue(100);
            break;

        case Worker::RESULT_NO_STEAM:
            resetProgress();
            QMessageBox::information(this, windowTitle(), "Steam is not running" );
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
        ui->status->setFormat("Updating (may take a while)");
        ui->status->setValue(33);
    }
    else
    {
        workerOperate(Worker::TASK_INSTALL);
        ui->status->setFormat("Installing (may take a while)");
        ui->status->setValue(50);
    }
}

void MainWindow::resetProgress()
{
    ui->status->setFormat("");
    ui->status->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settings;

    thread.quit();
    thread.wait();
}

