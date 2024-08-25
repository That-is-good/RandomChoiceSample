#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) : QDialog(parent) , ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
}

SettingMenu::~SettingMenu()
{
    delete ui;
}

void SettingMenu::on_animationTime_valueChanged(int value)
{
    this->animationTime = value;
    qDebug() << "动画时间: " << value;
}


void SettingMenu::on_animationCnt_valueChanged(int value)
{
    this->animationCnt = value;
    qDebug() << "动画次数" << value;
}


void SettingMenu::on_randDevMt_toggled(bool checked)
{
    if (checked){
        this->mode = false;
        qDebug()<< "梅森随机开启";
    }
}


void SettingMenu::on_MtSeed_toggled(bool checked)
{
    if (checked){
        this->mode = true;
        qDebug() << "梅森时间开启";
    }
}


void SettingMenu::on_EnterSeed_valueChanged(int arg1)
{
    this->seed = arg1;
    qDebug() << "随机种子" << arg1;
}

