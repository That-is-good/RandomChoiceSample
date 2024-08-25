#include "randomchoice.h"
#include "ui_randomchoice.h"

void RandomChoice::setITR(int cur){
    this->itr=this->weigths.begin();
    for (int i = 0;i < cur;++i){
        ++this->itr;
    }
}

int RandomChoice::checkWeight(QString s_weight){
    bool pass = false;
    int weight = s_weight.toInt(&pass);
    if (pass && weight >= 0){
        if (weight > 65535){
            ShowMsgBox("格式有误！权重不能超过65535！");
            weight = 1;
        }
    }
    else{
        ShowMsgBox("格式有误！权重只能是自然数！");
        weight = 1;
    }
    return weight;
}

QList<QStandardItem*> RandomChoice::AddEle(QString p = "1", QString q = "", int cur = -1){
    QList<QStandardItem*> addI;
    int weight = checkWeight(p);
    addI.append(new QStandardItem(QString::number(weight)));
    addI.append(new QStandardItem(q));

    setWeights(cur, weight);
    return addI;
}

void RandomChoice::setWeights(int cur,int weight){
    if (cur == -1){
        this->weigths.push_back(weight);
    }else if(weight == -1){
        setITR(cur);
        if (*itr != 0){
            --this->rCNT;
        }
        this->weigths.erase(itr);
        return;
    }
    else{
        setITR(cur);
        this->weigths.insert(itr, weight);
    }
    if (weight > 0){
        ++rCNT;
    }
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
    QObject::connect(PersonListItem, &QAbstractItemModel::dataChanged, this, &RandomChoice::on_personlist_chg);
    threadSample->setlist(&weigths);
    this->setAcceptDrops(true);
    readini();
}

RandomChoice::~RandomChoice()
{
    delete ui;
}

void RandomChoice::readini(){
    QFile iniReader("setting.ini");
    if (iniReader.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!iniReader.atEnd()){
            QByteArray l = iniReader.readLine().removeLast();
            qsizetype seprated = l.indexOf('=');
            QByteArray left = l.left(seprated);
            QByteArray right = l.mid(seprated + 1);
            int math_right = right.toInt();
            if (left == "font_family"){
                this->font.setFamily(right.toStdString().c_str());
            }else if(left == "font_size"){
                this->font.setPointSize(math_right);
            }else if(left == "anim_cnt"){
                if (math_right >= 8 && math_right <= 256){
                    this->threadSample->setaniTime(math_right);
                }else{
                    ShowMsgBox("动画次数只能在8～256.");
                }
            }else if(left == "anim_time"){
                if (math_right >= 8 && math_right <= 256){
                    this->threadSample->setonceTime(math_right);
                }else{
                    ShowMsgBox("动画时间只能在8～256.");
                }
            }else if(left == "rand_mode"){
                if (math_right == 0 || math_right == 1){
                    this->threadSample->setEng(math_right);
                }else{
                    ShowMsgBox("模式错误。");
                }
            }else{
                left = "未知的key: " + left;
                ShowMsgBox(left);
            }
        }
        effFont();
        iniReader.close();
    }else{
        ShowMsgBox("没有配置文件“setting.ini”!");
    }
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
        PersonListItem->insertRow(cur, AddEle("1", "", cur));
    }else{
        ShowMsgBox("请选中元素再插入.");
    }
}
//删除
void RandomChoice::on_pushButton_4_released()
{
    int cur = PersonList->currentIndex().row();
    if (cur >= 0){
        setWeights(cur, -1);
        PersonListItem->removeRow(cur);
    }
}
//清空
void RandomChoice::on_pushButton_5_released()
{
    weigths.clear();
    rCNT = 0;
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

void RandomChoice::effFont(){
    this->setFont(this->font);
    this->msgBox.setFont(this->font);
    this->res->setFont(this->font);
}
//设置字体
void RandomChoice::on_action_5_triggered()
{
    bool pressed = false;
    this->font = QFontDialog::getFont(&pressed);
    qDebug() << this->font.family();
    if (pressed){
        effFont();
    }
}

//生成结果
void RandomChoice::on_pushButton_released()
{
    if (!res->isHidden()){
        ShowMsgBox("窗口未关闭！");
        return;
    }

    int allCounts = PersonListItem->rowCount();
    if (allCounts <= 0){
        ShowMsgBox("元素数量不能为0！");
        return;
    }else {
        if(!states[1]){
            if (allCounts < this->cnts){
                ShowMsgBox("在不重复的情况下抽样数量不能超过元素数量！");
                return;
            }else if (this->rCNT < this->cnts){
                ShowMsgBox("权重有误，在不重复的情况下可能的结果数量小于抽取数量");
                return;
            }
        }
    }
    qDebug() << "真实元素数量" << this->rCNT;
    threadSample->setAllCnt(allCounts);

    threadSample->setItemModel(PersonListItem);
    threadSample->setRes(res);
    threadSample->start();

    res->show();
    res->exec();
    bool isnfinished = !threadSample->isFinished();
    if (isnfinished){
        threadSample->forcedFN(true);
        ShowMsgBox("抽样已强制结束。");
    }
    threadSample->wait();
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
    std::mt19937 gen;
    if (cntRow > 0){
        if (this->setting->mode){
            gen = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        }else
        {
            gen = std::mt19937(std::random_device()());
        }
        std::uniform_int_distribution<int> dist(0, cntRow - 1);
        QString arr;
        int chosen = 0;
        for (int i = 0; i < cntRow; ++i) {
            chosen = dist(gen);
            arr = this->PersonListItem->item(i, 0)->text();
            this->PersonListItem->item(i, 0)->setText(this->PersonListItem->item(chosen, 0)->text());
            this->PersonListItem->item(chosen, 0)->setText(arr);

            arr = this->PersonListItem->item(i, 1)->text();
            this->PersonListItem->item(i, 1)->setText(this->PersonListItem->item(chosen, 1)->text());
            this->PersonListItem->item(chosen, 1)->setText(arr);
        }
        this->itr = this->weigths.begin();
        for (int i = 0; i < cntRow; ++i) {
            *(this->itr) = this->PersonListItem->item(i, 0)->text().toUShort();
            ++(this->itr);
        }
    }
}
//设置菜单
void RandomChoice::on_action_2_triggered()
{
    this->setting->show();
    this->setting->exec();
    this->threadSample->setonceTime(this->setting->animationTime);
    this->threadSample->setaniTime(this->setting->animationCnt);
    this->threadSample->setSeed(this->setting->seed);
    this->threadSample->setEng(this->setting->mode);
}

void RandomChoice::on_animation_toggled(bool checked)
{
    threadSample->setAnimation(checked);
    this->states[0] = checked;
}

void RandomChoice::on_spinBox_valueChanged(int arg1)
{
    threadSample->setCnt(arg1);
    this->cnts = arg1;
}

void RandomChoice::on_repeated_toggled(bool checked)
{
    threadSample->setRepeated(checked);
    this->states[1] = checked;
}

void RandomChoice::on_personlist_chg(const QModelIndex &index)
{
    if (index.column() == 0){
        int weight = checkWeight(index.data().toString());
        this->PersonListItem->item(index.row())->setText(QString::number(weight));
        setITR(index.row());
        if (*itr == 0 && weight != 0){
            ++rCNT;
        }else if(*itr != 0 && weight == 0){
            --rCNT;
        }
        *itr = weight;
    }
}
