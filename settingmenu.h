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

private slots:
    void on_animationTime_valueChanged(int value);

    void on_animationCnt_valueChanged(int value);

    void on_randDevMt_toggled(bool checked);

    void on_MtSeed_toggled(bool checked);

    void on_EnterSeed_valueChanged(int arg1);

private:
    Ui::SettingMenu *ui;
    int animationTime = 64;
    int animationCnt = 32;
    int seed = 0;
    bool mode = true;
    /*
     * false    为梅森+随机
     * true     为梅森+时间
    */
};

#endif // SETTINGMENU_H
