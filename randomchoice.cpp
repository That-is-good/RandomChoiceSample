#include "randomchoice.h"
#include "ui_randomchoice.h"
#include <random>
#include <list>

QList<QStandardItem*> AddEle(QString p = "1", QString q = ""){
    QList<QStandardItem*> addI;
    addI.append(new QStandardItem(p));
    addI.append(new QStandardItem(q));
    return addI;
}

RandomChoice::RandomChoice(QWidget *parent) : QMainWindow(parent), ui(new Ui::RandomChoice)
{
    ui->setupUi(this);
    PersonList = this->findChild<QTableView*>("personlist");
    if (PersonList != nullptr){
        PersonListItem->setHorizontalHeaderLabels(this->headLabel);
        PersonList->horizontalHeader()->setStretchLastSection(true);
        PersonList->setModel(PersonListItem);
        PersonList->setAcceptDrops(true);
    }
    this->setAcceptDrops(true);
    Rdcnts = this->findChild<QSpinBox *>("spinBox");
    repeated = this->findChild<QCheckBox *>("repeated");
    animation = this->findChild<QCheckBox *>("animation");
    engset = this->findChild<QAction *>("action_6");
}

RandomChoice::~RandomChoice()
{
    delete ui;
}

void RandomChoice::ShowMsgBox(QString str){
    this->msgBox.setText(str);
    this->msgBox.show();
    this->msgBox.exec();
}
//文件读取
void RandomChoice::readFiletoTable(QString fn){
    QFile rdFile(fn);
    if (rdFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QByteArray rInChar;
        while (!rdFile.atEnd()){
            rInChar = rdFile.readLine().removeLast();
            qsizetype seprated = rInChar.indexOf('\t');
            if (seprated){
                QByteArray leftChar = rInChar.left(seprated);
                if (leftChar.isEmpty()){
                    leftChar = "1";
                }
                PersonListItem->appendRow(AddEle(leftChar ,rInChar.mid(seprated + 1)));
            }
        }
    }else{
        ShowMsgBox(fn + "无法打开。");
    }
}
//追加
void RandomChoice::on_pushButton_2_released()
{
    PersonListItem->appendRow(AddEle());
}
//插入
void RandomChoice::on_pushButton_3_released()
{
    int cur = PersonList->currentIndex().row();
    if (cur >= 0){
        PersonListItem->insertRow(cur, AddEle());
    }else{
        ShowMsgBox("请选中元素再插入.");
    }
}
//删除
void RandomChoice::on_pushButton_4_released()
{
    int cur = PersonList->currentIndex().row();
    if (cur >= 0)
        PersonListItem->removeRow(cur);
}
//清空
void RandomChoice::on_pushButton_5_released()
{
    PersonListItem->clear();
    PersonListItem->setHorizontalHeaderLabels(this->headLabel);
}
//打开
void RandomChoice::on_action_triggered()
{
    QString fn = QFileDialog::getOpenFileName(this, "打开文件");
    if (!fn.isEmpty())
        readFiletoTable(fn);
}
//退出
void RandomChoice::on_action_4_triggered()
{
    this->close();
}

//==================文件拖放==================
void RandomChoice::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (!urls.empty()){
        readFiletoTable(urls.first().toLocalFile());
    }
}

void RandomChoice::dragEnterEvent(QDragEnterEvent* event){
    if (event->mimeData()->hasFormat("text/uri-list")){
        event->acceptProposedAction();
    }
}
//==================文件拖放==================

//设置字体
void RandomChoice::on_action_5_triggered()
{
    bool pressed = false;
    this->font = QFontDialog::getFont(&pressed);
    if (pressed){
        this->setFont(this->font);
        this->msgBox.setFont(this->font);
        this->res->setFont(this->font);
    }
}

//生成结果
void RandomChoice::on_pushButton_released()
{
    std::list<int> weigths;
    int allCounts = PersonListItem->rowCount();
    if (allCounts <= 0){
        ShowMsgBox("元素数量不能为0！");
        return;
    }else if(!repeated->checkState() && allCounts < Rdcnts->value()){
        ShowMsgBox("在不重复的情况下抽样数量不能超过元素数量！");
        return;
    }
    int maxCan = 0;
    for (int i = 0; i < allCounts; ++i) {
        QString temp = PersonListItem->item(i, 0)->text();
        bool pass = false;
        int weigth = temp.toInt(&pass);
        if (pass){
            if (weigth > 65535){
                ShowMsgBox("格式有误！权重不能超过65535！");
                PersonList->selectRow(i);
                return;
            }
            weigths.push_back(weigth);
            if (weigth != 0){
                ++maxCan;
            }
        }else{
            ShowMsgBox("格式有误！权重只能是自然数！");
            PersonList->selectRow(i);
            return;
        }
    }
    if (!repeated->checkState() && maxCan < Rdcnts->value()){
        ShowMsgBox("权重有误，在不重复的情况下可能的结果数量小于抽取数量");
        return;
    }
    threadSample->setCnt(Rdcnts->value());
    threadSample->setAllCnt(allCounts);
    threadSample->setAnimation(animation->checkState());
    threadSample->setRepeated(repeated->checkState());
    threadSample->setItemModel(PersonListItem);
    threadSample->setRes(res);
    threadSample->setlist(&weigths);
    threadSample->start();

    res->show();
    res->exec();
    bool isnfinished = !threadSample->isFinished();
    if (isnfinished)
        ShowMsgBox("你已提前关闭窗口，但抽样不会结束。");
    threadSample->wait();
    if (isnfinished)
        ShowMsgBox("抽样已结束。");
    res->hide();

    res->clearText();
}


void RandomChoice::on_helpUse_triggered()
{
    ShowMsgBox(StrhelpStr);
}

//重排
void RandomChoice::on_pushButton_6_clicked()
{
    int cntRow = this->PersonListItem->rowCount();
    if (cntRow > 0){
        std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> dist(0, cntRow - 1);
        QStandardItem *arr[4];
        int chosen = 0;
        for (int i = 0; i < cntRow; ++i) {
            chosen = dist(gen);
            arr[0] = this->PersonListItem->item(i, 0)->clone();
            arr[1] = this->PersonListItem->item(i, 1)->clone();
            arr[2] = this->PersonListItem->item(chosen, 0)->clone();
            arr[3] = this->PersonListItem->item(chosen, 1)->clone();

            this->PersonListItem->setItem(i, 0, arr[2]);
            this->PersonListItem->setItem(i, 1, arr[3]);
            this->PersonListItem->setItem(chosen, 0, arr[0]);
            this->PersonListItem->setItem(chosen, 1, arr[1]);
        }
    }
}


void RandomChoice::on_action_2_triggered()
{
    this->setting->show();
    this->setting->exec();
    this->threadSample->setonceTime(this->setting->animationTime->value());
    this->threadSample->setaniTime(this->setting->animationCnt->value());
    short Spwmode = 0;
    if (this->setting->mttAndrand->isChecked()){
        Spwmode = 1;
    }else if (this->setting->mttAndseed->isChecked()){
        Spwmode = 2;
        this->threadSample->setSeed(this->setting->seedEnter->value());
    }
    this->threadSample->setEng(Spwmode);
}

