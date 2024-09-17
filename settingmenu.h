#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QDialog>
#include <QRadioButton>
#include <QSlider>

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

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SettingMenu *ui;
    QSlider* C_animationTime;
    QSlider* C_animationCnt;
    QRadioButton* C_mode_randDevMt;
    QRadioButton* C_mode_MtSeed;

    int animationTime = 64;
    int animationCnt = 32;
    bool mode = true;
    /*
     * false    为梅森+随机
     * true     为梅森+时间
    */
};

#endif // SETTINGMENU_H
