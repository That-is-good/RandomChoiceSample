#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) : QDialog(parent) , ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
    this->C_mode_randDevMt = this->findChild<QRadioButton*>("randDevMt");
    this->C_mode_MtSeed = this->findChild<QRadioButton*>("MtSeed");
    this->C_animationTime = this->findChild<QSlider*>("animationTime");
    this->C_animationCnt = this->findChild<QSlider*>("animationCnt");
}

SettingMenu::~SettingMenu()
{
    delete ui;
}

void SettingMenu::on_buttonBox_accepted()
{
    this->animationTime = this->C_animationTime->value();
    this->animationCnt = this->C_animationCnt->value();
    if (this->C_mode_randDevMt->isChecked()){
        this->mode = 0;
    }else{
        this->mode = 1;
    }
}


void SettingMenu::on_buttonBox_rejected()
{
    this->C_animationTime->setValue(this->animationTime);
    this->C_animationCnt->setValue(this->animationCnt);
    if (this->mode == 0){
        this->C_mode_randDevMt->click();
    }else{
        this->C_mode_MtSeed->click();
    }
}

