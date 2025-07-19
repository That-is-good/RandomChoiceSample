#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include <QStandardItemModel>
#include <QListView>
#include <qfont.h>

namespace Ui {
class ShowResult;
}

class ShowResult : public QDialog
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();
    void resetText(QString str);
    void addText(QString str);
private:
    QStandardItemModel *ResultListItem = new QStandardItemModel(this);
    Ui::ShowResult *ui;

};

#endif // SHOWRESULT_H
