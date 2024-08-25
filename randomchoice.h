#ifndef RANDOMCHOICE_H
#define RANDOMCHOICE_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QFileDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QUrl>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QSpinBox>
#include <QCheckBox>
#include <QFile>

#include <list>
#include <random>
#include "showsamples.h"
#include "showresult.h"
#include "settingmenu.h"

#define StrhelpStr "本程序由NewJay好果汁无限公司制作\n\
1.动画指抽样时的变化动画，具体请到设置->详细调节。\n\
2.引擎是指抽样时采用的随机数方法，一般推荐linux系统用mt+randev。\n\
3.文件中写权重可以通过该格式 \"[权重]+[制表符]+[元素]\"不写默认为1,\n\
4.配置文件为“setting.ini”，其中有以下参数\n\
font_family为字体类型, font_size为字体大小\n\
anim_cnt为动画次数, anim_time为动画时间\n\
rand_mode为随机类型\
"

QT_BEGIN_NAMESPACE
namespace Ui {
class RandomChoice;
}
QT_END_NAMESPACE

class RandomChoice : public QMainWindow
{
    Q_OBJECT

public:
    QList<QStandardItem*> AddEle(QString, QString, int);
    void setWeights(int, int);
    int checkWeight(QString);
    void setITR(int);
    void effFont();
    void readini();
    RandomChoice(QWidget *parent = nullptr);
    ~RandomChoice();
    void readFiletoTable(QString fn);
    void ShowMsgBox(QString str);
protected:
    virtual void dragEnterEvent(QDragEnterEvent* event) override;
    virtual void dropEvent(QDropEvent *event) override;

private slots:
    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_4_released();

    void on_pushButton_5_released();

    void on_action_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_pushButton_released();

    void on_helpUse_triggered();

    void on_pushButton_6_clicked();

    void on_action_2_triggered();

    void on_animation_toggled(bool checked);

    void on_spinBox_valueChanged(int arg1);

    void on_repeated_toggled(bool checked);

    void on_personlist_chg(const QModelIndex &);

private:
    std::list<unsigned short>::iterator itr;
    std::list<unsigned short> weigths;
    bool states[2] = {true, false};
    /*
     * 0    动画
     * 1    重复
    */
    int cnts = 1;
    unsigned short rCNT = 0;
    Ui::RandomChoice *ui;
    QFont font;
    QTableView* PersonList;
    QStandardItemModel *PersonListItem = new QStandardItemModel(this);
    QMessageBox msgBox = QMessageBox(this);
    ShowResult *res = new ShowResult();
    SettingMenu *setting = new SettingMenu();
    QAction *engset;
    const QStringList headLabel = QStringList() << "权重" << "元素";
    ShowSamples* threadSample = new ShowSamples(this);
};

#endif // RANDOMCHOICE_H
