#include "oflauncher.hpp"


OFLauncher::OFLauncher(QWidget *parent) : QMainWindow(parent)
{
    actionResetPath = new QAction(this);

    for (int i = 0; i < languageCount; ++i)
    {
        languages[i] = new QAction(this);
        languages[i]->setText(languageName[i]);
    }

    mainWidget = new QWidget(this);

    menuBar = new QMenuBar(this);
    menuSettings = new QMenu(menuBar);
    menuLanguage = new QMenu(menuBar);


    setupUi(this);
    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);

}

OFLauncher::~OFLauncher() {}

void OFLauncher::setupUi(QMainWindow *OFLauncher)
{
    //if (OFLauncher->objectName().isEmpty())
    //    OFLauncher->setObjectName("OFLauncher");
    OFLauncher->resize(948, 521);
    OFLauncher->setMinimumSize(QSize(948, 521));
    OFLauncher->setMaximumSize(QSize(948, 521));
    QIcon icon;
    icon.addFile(":/icons/images/icon.ico");
    OFLauncher->setWindowIcon(icon);
    OFLauncher->setStyleSheet(""
    "QLabel, QPushButton, QProgressBar {"
    "   color: white;"
    "}"
    ""
    "QLabel, QLineEdit {"
    "   background-color: rgba(35, 38, 41, 130);"
    "   border: none;"
    "}"
    ""
    "#mainWidget {"
    "   background-image: url(:/banners/images/background_small.png);"
    "}"
    ""
    "#playButton {"
    "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 50), stop:0.973366 rgba(0, 0, 0, 175), stop:0.975787 rgba(134, 76, 154, 255));\n"
    "   border: none;"
    "}"
    ""
    "QProgressBar {"
    "   text-align: left;"
    "   border: none;"
    "   background-color: rgba(0, 0, 0, 130);"
    "}"
    ""
    "QProgressBar::chunk {"
    "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,"
    "                                     stop:0 rgba(51, 37, 95, 255),"
    "                                     stop:1 rgba(160, 91, 185, 255));"
    "   border: none;"
    "}"
    "");

    mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
    verticalLayout = new QVBoxLayout(mainWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    QSpacerItem *topSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalLayout->addItem(topSpacer);

    headerLayout = new QHBoxLayout();
    headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
    QSpacerItem* leftSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    headerLayout->addItem(leftSpacer);

    QLabel* logo = new QLabel(mainWidget);
    logo->setText("<html><head/><body><p align=\"center\"><img src=\":/logos/images/logo_small.png\"/></p></body></html>");

    headerLayout->addWidget(logo);

    QSpacerItem* rightSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    headerLayout->addItem(rightSpacer);


    verticalLayout->addLayout(headerLayout);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalLayout_3->setContentsMargins(20, -1, -1, -1);
    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    launchRow = new QHBoxLayout();
    launchRow->setObjectName(QString::fromUtf8("launchRow"));
    launchText = new QLabel(mainWidget);
    launchText->setObjectName(QString::fromUtf8("launchText"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(launchText->sizePolicy().hasHeightForWidth());
    launchText->setSizePolicy(sizePolicy);
    launchText->setMinimumSize(QSize(140, 0));
    launchText->setStyleSheet(QString::fromUtf8(""));
    launchText->setAlignment(Qt::AlignCenter);

    launchRow->addWidget(launchText);

    launchEdit = new QLineEdit(mainWidget);
    launchEdit->setObjectName(QString::fromUtf8("launchEdit"));
    launchEdit->setMinimumSize(QSize(0, 25));
    launchEdit->setStyleSheet(QString::fromUtf8(""));
    launchEdit->setAlignment(Qt::AlignCenter);

    launchRow->addWidget(launchEdit);


    verticalLayout_2->addLayout(launchRow);

    pathRow = new QHBoxLayout();
    pathText = new QLabel(mainWidget);
    sizePolicy.setHeightForWidth(pathText->sizePolicy().hasHeightForWidth());
    pathText->setSizePolicy(sizePolicy);
    pathText->setMinimumSize(QSize(140, 0));
    pathText->setAlignment(Qt::AlignCenter);

    pathRow->addWidget(pathText);

    pathEdit = new QLineEdit(mainWidget);
    pathEdit->setMinimumSize(QSize(0, 25));
    pathEdit->setAlignment(Qt::AlignCenter);

    pathRow->addWidget(pathEdit);


    verticalLayout_2->addLayout(pathRow);


    horizontalLayout_3->addLayout(verticalLayout_2);

    horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout_3->addItem(horizontalSpacer);

    playButton = new QPushButton(mainWidget);
    QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(playButton->sizePolicy().hasHeightForWidth());
    playButton->setSizePolicy(sizePolicy1);
    playButton->setMinimumSize(QSize(200, 0));

    horizontalLayout_3->addWidget(playButton);


    verticalLayout->addLayout(horizontalLayout_3);

    verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

    verticalLayout->addItem(verticalSpacer_2);

    progressBar = new QProgressBar(mainWidget);
    //progressBar->setValue(92);
    progressBar->setAlignment(Qt::AlignCenter);

    verticalLayout->addWidget(progressBar);

    OFLauncher->setCentralWidget(mainWidget);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 948, 29));
    
    menuSettings->setObjectName("menuSettings");
    menuLanguage->setObjectName("menuLanguage");
    OFLauncher->setMenuBar(menuBar);

    menuBar->addAction(menuSettings->menuAction());
    menuBar->addAction(menuLanguage->menuAction());
    menuSettings->addAction(actionResetPath);

    for (int i = 0; i < languageCount; ++i)
    {
        menuLanguage->addAction(languages[i]);
    }

    retranslateUi(OFLauncher);

    QMetaObject::connectSlotsByName(OFLauncher);
} // setupUi

void OFLauncher::retranslateUi(QMainWindow *OFLauncher)
{
    OFLauncher->setWindowTitle(QCoreApplication::translate("OFLauncher", "OFLauncher mockup", nullptr));
    actionResetPath->setText(QCoreApplication::translate("OFLauncher", "Reset Path", nullptr));
    launchText->setText("<html><head/><body><p><span style=\" font-style:italic;\">Launch Options</span></p></body></html>");
    pathText->setText("<html><head/><body><p><span style=\" font-style:italic;\"> Open Fortress Path </span></p></body></html>");
    playButton->setText(QCoreApplication::translate("OFLauncher", "PLAY", nullptr));
    progressBar->setFormat(QCoreApplication::translate("OFLauncher", "Downloading Updates (%p%)", nullptr));
    menuSettings->setTitle(QCoreApplication::translate("OFLauncher", "Settings", nullptr));
    menuLanguage->setTitle(QCoreApplication::translate("OFLauncher", "Language", nullptr));
} // retranslateUi
