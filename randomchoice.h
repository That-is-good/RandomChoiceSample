#pragma once
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
#include <qlist.h>
#include <qrandom.h>
#include <qregularexpression.h>
#include "content.h"
#include "floatwindow.h"
#include "regExpLimit.h"
#include "showsamples.h"
#include "settingmenu.h"

#define StrhelpStr "1.动画指抽样时的变化动画，具体请到设置->详细调节。\n2.文件中写权重可以通过该格式 \"[权重],[元素]\"不写默认为1。"

QT_BEGIN_NAMESPACE
namespace Ui {
class RandomChoice;
}
QT_END_NAMESPACE


QFont getPersistentFont(bool* ok, QWidget* parent = nullptr);

class RandomChoice : public QMainWindow
{
    Q_OBJECT

public:
    RandomChoice(QWidget *parent = nullptr);
    ~RandomChoice();
    void readFiletoTable(QString fn);
    void ShowMsgBox(QString str);
    void AddEle(QString, QString, int);
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
    Hitsuyo need;
    QMessageBox msgBox = QMessageBox(this);
    QSpinBox *Rdcnts;
    QCheckBox *repeated;
    QCheckBox *animation;
    SettingMenu *setting = new SettingMenu();
    const QStringList headLabel = QStringList() << "权重" << "元素";
    FloatingWidget* flt = new FloatingWidget(this);
    RegexValidatorDelegate* onlyNumber99999 = new RegexValidatorDelegate("^(\\d{1,5})$");
};

#endif // RANDOMCHOICE_H
