#ifndef BUBBLEWINDOW_H
#define BUBBLEWINDOW_H

#include <QDialog>
#include <QHoverEvent>
//#include <QPushButton>

namespace Ui {
class BubbleWindow;
}

class BubbleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BubbleWindow(QWidget *parent = nullptr);
    ~BubbleWindow();
    //QPushButton* Showbtn;
private slots:
    void on_pushButton_clicked();
    void mousePressEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent* event)override;
signals:
    void startChoosing();
private:
    Ui::BubbleWindow *ui;

    bool m_bIsPressed = false;
    QPointF m_dragPos;
};

#endif // BUBBLEWINDOW_H
