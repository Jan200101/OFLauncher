#include <QFontDatabase>

#include <iostream>

#include "mainwindow.hpp"
#include "./ui_mainwindow.h"
#include "workers.hpp"

#define FONT "TF2Build"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);

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

    svnWorker* th = new svnWorker;
    th->moveToThread(&thread);

    connect(&thread, &QThread::finished, th, &QObject::deleteLater);
    connect(this, &MainWindow::operateSVN, th, &svnWorker::doWork);
    //connect(th, &svnWorker::resultReady, this, &MainWindow::handleSVN);

    thread.start();

    //operateSVN(svnWorker::SVN_INSTALL);

    connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(settingsWindow()));

    settings = new Settings(this);
    settings->setModal(false);
    //connect(settings, SIGNAL(visibleChanged()), this, SLOT(enable()));

    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(install()));

    qRegisterMetaType<svnWorker::svnTasks>();
    qRegisterMetaType<svnWorker::svnResults>();

}

void MainWindow::handleSVN(const enum svnWorker::svnResults &)
{

}

void MainWindow::settingsWindow()
{
    settings->show();
    //this->setEnabled(false);
}

void MainWindow::enable()
{
    this->setEnabled(true);
}

void MainWindow::install()
{
    operateSVN(svnWorker::SVN_INSTALL);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete settings;

    thread.quit();
    thread.wait();
}

