#include "showresult.h"
#include "ui_showresult.h"

ShowResult::ShowResult(QWidget *parent) : QDialog(parent), ui(new Ui::ShowResult)
{
    ui->setupUi(this);
    ResultList = this->findChild<QListView*>("ResultList");
    ResultList->setModel(ResultListItem);
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::resetText(int i, QString str){
    ResultListItem->item(i)->setText(str);
}

void ShowResult::addText(QString str){
    ResultListItem->appendRow(new QStandardItem(str));
}

void ShowResult::clearText(){
    ResultListItem->clear();
}
