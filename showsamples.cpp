#include "showsamples.h"



ShowSamples::ShowSamples(QObject *parent) : QThread(parent)
{

}
void ShowSamples::initialise(Hitsuyo data)
{
    this->data = data;
    this->data.weight = new int[this->data.all];
    this->data.content = new QString[this->data.all];
    for (int i = 0; i < this->data.all; ++i)
    {
        this->data.weight[i] = data.weight[i];
        this->data.content[i] = data.content[i];
    }
}
void ShowSamples::ClearMemory()
{
    if (!data.repeat) {
        delete[]chosen;
        chosen = nullptr;
    }
    delete[] this->data.weight;
    delete[] this->data.content;
    this->data.weight = nullptr;
    this->data.content = nullptr;
}
void ShowSamples::run() {
    connect(data.resultS, &QDialog::destroyed
        , this, [&]() {
            data.resultS = nullptr;
            ClearMemory();
            this->exit();
        });
    if (!data.repeat) {
        chosen = new bool[data.all];
        for (int i = 0; i < data.all; ++i) {
            chosen[i] = false;
        }
    }
    if (data.mode) {
        rd.seed(data.seed);
    }
    int* sum = new int[data.all];
    int index = 0;
    sum[0] = data.weight[0];
    for (int i = 1; i < data.all; ++i)
    {
        sum[i] = data.weight[i] + sum[i - 1];
    }
    for (int i = 0; i < data.cnt; ++i) {
        int haschosen = GetIndex(sum, data.all, rd.system()->bounded(1, sum[data.all - 1] + 1));
        data.resultS->addText(data.content[haschosen]);
        if (data.anime) {
            for (int j = 0; j < data.count; ++j) {
                haschosen = GetIndex(sum, data.all, rd.system()->bounded(1, sum[data.all - 1] + 1));
                if (data.resultS == nullptr)
                {
                    ClearMemory();
                    return;
                }
                data.resultS->resetText(data.content[haschosen]);
                QThread::msleep(data.time);
            }
        }
        if (!data.repeat) {
            while (chosen[haschosen]) {
                if (data.resultS == nullptr)
                {
                    ClearMemory();
                    return;
                }
                haschosen = GetIndex(sum, data.all, rd.system()->bounded(1, sum[data.all - 1] + 1));
            }
            data.resultS->resetText(data.content[haschosen]);
            chosen[haschosen] = true;
        }
    }
    ClearMemory();}
