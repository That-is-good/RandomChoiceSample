#include "randomchoice.h"
#include "ui_randomchoice.h"

QFont getPersistentFont(bool* ok, QWidget* parent)
{
    static QFont lastFont;

    QFontDialog dlg(parent);
    if (lastFont != QFont()) {
        dlg.setCurrentFont(lastFont);
    }

    int result = dlg.exec();
    if (ok) *ok = (result == QDialog::Accepted);

    if (result == QDialog::Accepted) {
        lastFont = dlg.selectedFont();
    }

    return dlg.selectedFont();
}

void RandomChoice::AddEle(QString p, QString q, int cur = -1){
    QList<QStandardItem*> addI(2);
    addI[0] = (new QStandardItem(p));
    addI[1] = (new QStandardItem(q));
    if (cur >= 0)
    {
        this->PersonListItem->insertRow(cur, addI);
    }
    else {
        this->PersonListItem->appendRow(addI);
    }
    
}

RandomChoice::RandomChoice(QWidget* parent) : QMainWindow(parent), ui(new Ui::RandomChoice)
{
    ui->setupUi(this);
    PersonList = ui->personlist;
    if (PersonList != nullptr) {
        PersonListItem->setHorizontalHeaderLabels(this->headLabel);
        PersonList->horizontalHeader()->setStretchLastSection(true);
        PersonList->setModel(PersonListItem);
        PersonList->setAcceptDrops(true);
    }
    ui->personlist->setItemDelegateForColumn(0, onlyNumber99999);
    this->setAcceptDrops(true);
    Rdcnts = ui->spinBox;
    repeated = ui->repeated;
    animation = ui->animation;
    connect(ui->action_3, &QAction::triggered, this, [&]() {
        this->flt->show();
        });
    connect(flt, &FloatingWidget::Start, this, [&]() {on_pushButton_released(); });
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
void RandomChoice::readFiletoTable(QString fn) {
    QFile rdFile(fn);
    if (!rdFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ShowMsgBox(fn + "无法打开。错误: " + rdFile.errorString());
        return;
    }

    QTextStream in(&rdFile);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        int separatorPos = line.indexOf(',');

        QString leftPart, rightPart;

        if (separatorPos != -1) {  // 存在逗号
            leftPart = line.left(separatorPos).trimmed();
            rightPart = line.mid(separatorPos + 1).trimmed();

            if (leftPart.isEmpty()) {
                leftPart = "1";  // 逗号前为空则默认为1
            }
        }
        else {  // 不存在逗号
            leftPart = "1";      // 默认leftPart为1
            rightPart = line;    // 整行作为rightPart
        }

        AddEle(leftPart.toUtf8(), rightPart.toUtf8());
    }
}
//追加
void RandomChoice::on_pushButton_2_released()
{
    AddEle("1", "");
}
//插入
void RandomChoice::on_pushButton_3_released()
{
    int cur = PersonList->currentIndex().row();
    if (cur >= 0){
        AddEle("1", "", cur);
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
    this->font = getPersistentFont(&pressed, this);
    if (pressed){
        this->setFont(this->font);
        this->msgBox.setFont(this->font);
    }
}

//生成结果
void RandomChoice::on_pushButton_released()
{
    int allCounts = PersonListItem->rowCount();
    if (allCounts <= 0){
        ShowMsgBox("元素数量不能为0！");
        return;
    }else if(!repeated->checkState() && allCounts < Rdcnts->value()){
        ShowMsgBox("在不重复的情况下抽样数量不能超过元素数量！");
        return;
    }
    this->need.weight = new int[allCounts];
    this->need.content = new QString[allCounts];
    int maxCan = 0;
    for (int i = 0; i < allCounts; ++i) {
        QString temp = PersonListItem->item(i, 0)->text();
        int weigth = temp.toInt();

        this->need.weight[i] = weigth;
        this->need.content[i] = PersonListItem->item(i, 1)->text();
        if (weigth > 0){
            ++maxCan;
        }
    }
    if (!repeated->checkState() && maxCan < Rdcnts->value()){
        ShowMsgBox("权重有误，在不重复的情况下可能的结果数量小于抽取数量");
        return;
    }
    this->need.all = allCounts;
    this->need.anime = animation->checkState();
    this->need.cnt = Rdcnts->value();
    this->need.repeat = repeated->checkState();
    this->need.mode = this->setting->seed;
    this->need.seed = this->setting->seedEnter->value();
    this->need.time = this->setting->animationTime->value();
    this->need.count = this->setting->animationCnt->value();
    this->need.resultS = new ShowResult(this);
    this->need.resultS->setAttribute(Qt::WA_DeleteOnClose, true);
    ShowSamples* res = new ShowSamples(this);
    this->need.resultS->setFont(this->font);
    this->need.resultS->show();
    res->initialise(this->need);
    res->start();
    delete[] this->need.weight;
    delete[] this->need.content;
    this->need.weight = nullptr;
    this->need.content = nullptr;
}


void RandomChoice::on_helpUse_triggered()
{
    ShowMsgBox(StrhelpStr);
}

//重排
static void swapRows(QStandardItemModel* model, int rowA, int rowB) {
    // 检查模型有效性
    if (!model) return;

    // 检查行号有效性
    const int rowCount = model->rowCount();
    if (rowA < 0 || rowB < 0 || rowA >= rowCount || rowB >= rowCount || rowA == rowB) {
        return;
    }

    // 确保先处理较小的行号
    const int lowerRow = qMin(rowA, rowB);
    const int upperRow = qMax(rowA, rowB);

    // 取出两行数据
    QList<QStandardItem*> upperItems = model->takeRow(upperRow);
    QList<QStandardItem*> lowerItems = model->takeRow(lowerRow);

    // 重新插入交换后的行
    model->insertRow(lowerRow, upperItems);
    model->insertRow(upperRow, lowerItems);
}

void RandomChoice::on_pushButton_6_clicked()
{
    int cntRow = this->PersonListItem->rowCount();
    if (cntRow > 0){
        QRandomGenerator64 rd;
        int chosen = 0;
        for (int i = 0; i < cntRow - 1; ++i) {
            chosen = rd.system()->bounded(i + 1, cntRow);
            if (chosen != i)
            {
                swapRows(this->PersonListItem, i, chosen);
            }
        }
    }
}


void RandomChoice::on_action_2_triggered()
{
    this->setting->show();
}

