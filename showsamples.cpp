#include "showsamples.h"

ShowSamples::ShowSamples(QObject *parent) : QThread(parent)
{
    start_T = std::chrono::high_resolution_clock::now().time_since_epoch().count();
}

void ShowSamples::setonceTime(int onceT){
    this->onceTime = onceT;
}
void ShowSamples::setaniTime(int aniT){
    this->aniTime = aniT;
}
void ShowSamples::setCnt(int cnt){
    this->maxCnt = cnt;
}
void ShowSamples::setAllCnt(int allcnt){
    this->allCounts = allcnt;
}
void ShowSamples::setEng(bool eng){
    this->engset = eng;
}
void ShowSamples::setlist(std::list<unsigned short> * list){
    this->weights = list;
}
void ShowSamples::setItemModel(QStandardItemModel *itemModel){
    this->PersonListItem = itemModel;
}
void ShowSamples::setRes(ShowResult* uiRes){
    this->res = uiRes;
}
void ShowSamples::setAnimation(bool anim){
    this->animation = anim;
}
void ShowSamples::setRepeated(bool rep){
    this->repeated = rep;
}

void ShowSamples::forcedFN(bool t){
    this->forcedFinsh = t;
}

void ShowSamples::run(){
    if (!repeated){
        chosen = new bool[this->allCounts];
        for (int i = 0; i < this->allCounts; ++i){
            chosen[i] = false;
        }
    }
    std::mt19937_64 gen;
    if (this->engset == false){
        gen = std::mt19937_64(std::random_device()());
        qDebug() << "梅森随机";
    }else{
        long long deltaT = std::chrono::high_resolution_clock::now().time_since_epoch().count() - start_T;
        gen = std::mt19937_64(deltaT);
        qDebug() << "梅森时间种子: " << deltaT;
        if (deltaT > 4294967296){
            start_T = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        }
    }
    qDebug() << "动画时间" << onceTime;
    qDebug() << "动画次数" << aniTime;
    std::discrete_distribution<int> distr(this->weights->begin(), this->weights->end());
    int haschosen = 0;
    for (int i = 0; i < this->maxCnt; ++i) {
        res->addText("");
        if (animation){
            for (int j = 1; j < aniTime; ++j) {
                res->resetText(i, PersonListItem->item(j%allCounts, 1)->text());
                QThread::msleep(onceTime);
            }
        }
        haschosen = distr(gen);
        res->resetText(i, PersonListItem->item(haschosen, 1)->text());
        if (!repeated){
            while (chosen[haschosen]){
                haschosen = distr(gen);
            }
            res->resetText(i, PersonListItem->item(haschosen, 1)->text());
            chosen[haschosen] = true;
        }
        qDebug() << "索引: " << haschosen;
        if (forcedFinsh){
            forcedFinsh = false;
            break;
        }
    }

    if (!repeated && chosen != nullptr){
        delete []chosen;
    }else if(chosen != nullptr){
        chosen = nullptr;
    }
}
