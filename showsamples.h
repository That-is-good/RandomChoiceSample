#pragma once
#ifndef SHOWSAMPLES_H
#define SHOWSAMPLES_H

#include <QThread>
#include <qrandom.h>
#include "content.h"
#include "showresult.h"

class ShowSamples : public QThread
{
    Q_OBJECT
public:
    explicit ShowSamples(QObject *parent = nullptr);
    void initialise(Hitsuyo data);
    void ClearMemory();
    Hitsuyo data;
    bool* chosen;
    QRandomGenerator64 rd;
protected:
    void run();
};

#endif // SHOWSAMPLES_H
