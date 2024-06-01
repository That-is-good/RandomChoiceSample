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

#include "showsamples.h"
#include "showresult.h"
#include "settingmenu.h"

#define StrhelpStr "本程序由NewJay好果汁无限公司制作\n1.动画指抽样时的变化动画，具体请到设置->详细调节。\n2.引擎是指抽样时采用的随机数方法，一般推荐linux系统用randomdevice。\n3.文件中写权重可以通过该格式 \"[权重]+[制表符]+[元素]\"不写默认为1,\n\t制表符一般是按Tab键输入。"

QT_BEGIN_NAMESPACE
namespace Ui {
class RandomChoice;
}
QT_END_NAMESPACE

class RandomChoice : public QMainWindow
{
    Q_OBJECT

public:
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

private:
    Ui::RandomChoice *ui;
    QFont font;
    QTableView* PersonList;
    QStandardItemModel *PersonListItem = new QStandardItemModel(this);
    QMessageBox msgBox = QMessageBox(this);
    QSpinBox *Rdcnts;
    QCheckBox *repeated;
    QCheckBox *animation;
    ShowResult *res = new ShowResult();
    SettingMenu *setting = new SettingMenu();
    QAction *engset;
    const QStringList headLabel = QStringList() << "权重" << "元素";
    ShowSamples* threadSample = new ShowSamples(this);
};

#endif // RANDOMCHOICE_H
