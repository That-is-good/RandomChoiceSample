#pragma once

#ifndef FLOATINGWIDGET_H
#define FLOATINGWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QDebug>

class FloatingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FloatingWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    bool event(QEvent* event) override;
signals:
    void Start();
private slots:

    void onDoubleClicked();

private:
    bool m_dragging;
    QPoint m_dragPosition;
};

#endif // FLOATINGWIDGET_H