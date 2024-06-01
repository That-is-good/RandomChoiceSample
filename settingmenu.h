#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QDialog>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>

class RandomChoice;

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QDialog
{
    Q_OBJECT

public:
    friend class RandomChoice;
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();

private:
    Ui::SettingMenu *ui;
    QSlider *animationTime;
    QSlider *animationCnt;
    QRadioButton *mttAndrand;
    QRadioButton *mttAndseed;
    QSpinBox *seedEnter;
};

#endif // SETTINGMENU_H
