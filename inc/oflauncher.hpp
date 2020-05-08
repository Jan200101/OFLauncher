#ifndef OFLAUNCHER_HPP
#define OFLAUNCHER_HPP

#include <QMainWindow>

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

// always add your language before languageEND
enum {
    languageEnglish = 0,
    languageGerman,
    languageEND,
    languageCount = languageEND
};

// always use the native version of the name
static const char* languageName[languageCount] = {
	"english",
	"Deutsch"
};


class OFLauncher : public QMainWindow
{
    Q_OBJECT

private:
    QAction *actionResetPath;

    QWidget *mainWidget;
    QVBoxLayout *verticalLayout;
    //QSpacerItem *topSpacer;
    QHBoxLayout *headerLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *logo;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *launchRow;
    QLabel *launchText;
    QLineEdit *launchEdit;
    QHBoxLayout *pathRow;
    QLabel *pathText;
    QLineEdit *pathEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *playButton;
    QSpacerItem *verticalSpacer_2;
    QProgressBar *progressBar;
    QMenuBar *menuBar;
    QMenu *menuSettings;
    QMenu *menuLanguage;

    QAction *languages[languageCount];
public:
    OFLauncher(QWidget *parent = nullptr);
    ~OFLauncher();

    void setupUi(QMainWindow *OFLauncher);
    void retranslateUi(QMainWindow *OFLauncher);
};
#endif // OFLAUNCHER_HPP
