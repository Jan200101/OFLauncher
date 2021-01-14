#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QWidget>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Settings; }
QT_END_NAMESPACE

class Settings : public QDialog
{
    Q_OBJECT

public:
    Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;
};
#endif // SETTINGS_HPP
