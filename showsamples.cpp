#include "showsamples.h"

ShowSamples::ShowSamples(QObject *parent) : QThread(parent)
{

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
void ShowSamples::setlist(std::list<int> * list){
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

void ShowSamples::setSeed(unsigned long seed){
    if (seed == 0){
        this->SUMseed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    }else{
        this->SUMseed = seed;
    }
}

void ShowSamples::run(){
    if (!repeated){
        chosen = new bool[this->allCounts];
        for (int i = 0; i < this->allCounts; ++i){
            chosen[i] = false;
        }
    }
    std::random_device rd;
    std::mt19937 gen;
    if (this->engset == 1){
        gen = std::mt19937(rd());
    }else if(this->engset == 2){
        gen = std::mt19937(this->SUMseed);
    }
    std::discrete_distribution<int> distr(this->weights->begin(), this->weights->end());
    for (int i = 0; i < this->maxCnt; ++i) {
        int haschosen = distr(gen);
        res->addText(PersonListItem->item(haschosen, 1)->text());
        if (animation){
            for (int j = 0; j < aniTime; ++j) {
                if (this->engset == 0){
                    haschosen = distr(rd);
                }else{
                    haschosen = distr(gen);
                }
                res->resetText(i, PersonListItem->item(haschosen, 1)->text());
                QThread::msleep(onceTime);
            }
        }
        if (!repeated){
            while (chosen[haschosen]){
                haschosen = distr(gen);
            }
            res->resetText(i, PersonListItem->item(haschosen, 1)->text());
            chosen[haschosen] = true;
        }
    }

    if (!repeated && chosen != nullptr){
        delete []chosen;
    }else if(chosen != nullptr){
        chosen = nullptr;
    }
}
