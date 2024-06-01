#ifndef SHOWSAMPLES_H
#define SHOWSAMPLES_H

#include <QThread>
#include <random>
#include <list>
#include <QStandardItemModel>

#include "showresult.h"


class ShowSamples : public QThread
{
    Q_OBJECT
public:
    explicit ShowSamples(QObject *parent = nullptr);
    void setCnt(int cnt);
    void setAllCnt(int allcnt);
    void setEng(bool);
    void setonceTime(int);
    void setaniTime(int);
    void setlist(std::list<int> *);
    void setItemModel(QStandardItemModel *);
    void setRes(ShowResult*);
    void setAnimation(bool);
    void setRepeated(bool);
    void setSeed(unsigned long);
protected:
    void run();
signals:
private:
    unsigned long SUMseed;
    int maxCnt = 0;
    int onceTime = 64;
    int aniTime = 32;
    int allCounts = 0;
    short engset = 0;
    bool animation = true;
    bool repeated = false;
    bool *chosen;
    std::list<int>* weights;
    QStandardItemModel *PersonListItem;
    ShowResult* res;
};

#endif // SHOWSAMPLES_H
