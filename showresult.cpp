#include "showresult.h"
#include "ui_showresult.h"

ShowResult::ShowResult(QWidget *parent) : QDialog(parent), ui(new Ui::ShowResult)
{
    ui->setupUi(this);
    ui->ResultList->setModel(ResultListItem);
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::resetText(QString str){
    ResultListItem->item(ResultListItem->rowCount() - 1)->setText(str);
}

void ShowResult::addText(QString str){
    ResultListItem->appendRow(new QStandardItem(str));
}