#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) : QDialog(parent) , ui(new Ui::SettingMenu)
{
    ui->setupUi(this);

    animationTime = ui->animationTime;
    animationCnt = ui->animationCnt;
    rand = ui->rand;
    seed = ui->seed;
    seedEnter = ui->EnterSeed;
}

SettingMenu::~SettingMenu()
{
    delete ui;
}
