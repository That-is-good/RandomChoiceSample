#include "bubblewindow.h"
#include "ui_bubblewindow.h"

BubbleWindow::BubbleWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BubbleWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_StyledBackground);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.50);
    this->setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    //Showbtn = this->findChild<QPushButton*>("pushButton");
}

BubbleWindow::~BubbleWindow()
{
    delete ui;
}

void BubbleWindow::on_pushButton_clicked()
{
    emit startChoosing();
}

void BubbleWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton){
        m_bIsPressed = true;
        m_dragPos = event->globalPosition() - this->pos();
    }
    QWidget::mousePressEvent(event);
}

void BubbleWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bIsPressed){
        if (!this->isMaximized() && !this->isFullScreen())
        {
            this->move((event->globalPosition() - m_dragPos).toPoint());
        }
    }
    QWidget::mouseMoveEvent(event);
}

void BubbleWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton){
        m_bIsPressed = false;
    }
    QWidget::mouseReleaseEvent(event);
}
