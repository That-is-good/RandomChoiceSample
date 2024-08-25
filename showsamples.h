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
    void setlist(std::list<unsigned short> *);
    void setItemModel(QStandardItemModel *);
    void setRes(ShowResult*);
    void setAnimation(bool);
    void setRepeated(bool);
    void setSeed(int);
    void forcedFN(bool);
protected:
    void run();
signals:
private:
    bool forcedFinsh = false;
    unsigned long long SUMseed = 0;
    int maxCnt = 1;
    int onceTime = 64;
    int aniTime = 32;
    int allCounts = 0;
    bool engset = true;
    bool animation = true;
    bool repeated = false;
    bool *chosen;
    std::list<unsigned short>* weights;
    QStandardItemModel *PersonListItem;
    ShowResult* res;
};

#endif // SHOWSAMPLES_H
