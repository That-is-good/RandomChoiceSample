#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) : QDialog(parent) , ui(new Ui::SettingMenu)
{
    ui->setupUi(this);

    animationTime = this->findChild<QSlider *>("animationTime");
    animationCnt = this->findChild<QSlider *>("animationCnt");
    mttAndrand = this->findChild<QRadioButton *>("randDevMt");
    mttAndseed = this->findChild<QRadioButton *>("MtSeed");
    seedEnter = this->findChild<QSpinBox *>("EnterSeed");
}

SettingMenu::~SettingMenu()
{
    delete ui;
}
