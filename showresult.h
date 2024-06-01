#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include <QStandardItemModel>
#include <QListView>

namespace Ui {
class ShowResult;
}

class ShowResult : public QDialog
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();
    void resetText(int i, QString str);
    void addText(QString str);
    void clearText();

private:
    QListView* ResultList;
    QStandardItemModel *ResultListItem = new QStandardItemModel(this);
    Ui::ShowResult *ui;

};

#endif // SHOWRESULT_H
