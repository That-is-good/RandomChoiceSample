#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QDialog>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QDialog
{
    Q_OBJECT

public:
    QSlider* animationTime;
    QSlider* animationCnt;
    QRadioButton* rand;
    QRadioButton* seed;
    QSpinBox* seedEnter;
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();

private:
    Ui::SettingMenu *ui;
};

#endif // SETTINGMENU_H
