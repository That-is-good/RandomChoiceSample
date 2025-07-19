#include "floatwindow.h"

FloatingWidget::FloatingWidget(QWidget* parent)
    : QWidget(parent), m_dragging(false)
{
    // 获取屏幕尺寸
    QScreen* screen = QGuiApplication::screenAt(QCursor::pos());
    if (!screen) screen = QGuiApplication::primaryScreen();

    // 考虑DPI缩放比例
    qreal dpi = screen->logicalDotsPerInch() / 96.0;

    // 计算基准尺寸（限制在合理范围）
    int baseSize = qMin(
        qMax(80, int(200 / dpi)),  // 最小80px，考虑DPI缩放
        int(screen->availableSize().width() / 16)  // 最大屏幕宽度的1/5
    );

    // 设置固定尺寸（避免意外变化）
    setFixedSize(baseSize, baseSize);
    QRect screenGeometry = screen->availableGeometry();

    // 根据屏幕宽度计算悬浮窗大小（例如屏幕宽度的1/8）
    int widgetSize = qMin(screenGeometry.width(), screenGeometry.height()) / 16;

    // 设置窗口属性
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);

    // 动态设置大小（保持正方形）
    resize(widgetSize, widgetSize);

    // 默认位置：屏幕右下角（留10%边距）
    move(screenGeometry.width()*0.6 - widgetSize * 1.1,
        screenGeometry.height()*0.6 - widgetSize * 1.1);

    // 其他样式设置...
    setStyleSheet("background: transparent;");
}

void FloatingWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 根据当前窗口大小动态计算渐变和字体
    int radius = width() / 2;
    QRadialGradient gradient(radius, radius, radius, radius, radius);
    gradient.setColorAt(0, QColor(100, 180, 255, 200));
    gradient.setColorAt(1, QColor(50, 120, 200, 150));

    painter.setBrush(gradient);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(rect());

    // 动态调整字体大小
    QFont font = painter.font();
    font.setPixelSize(radius / 3); // 字体大小为半径的1/3
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "\u5f00\u59cb");
}

void FloatingWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().topLeft();
        m_dragging = true;
        event->accept();
    }
}

void FloatingWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (m_dragging) {
        // 使用全局坐标计算位移，不重新获取屏幕信息
        QPoint newPos = event->globalPos() - m_dragPosition;
        move(newPos);
    }

}

void FloatingWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragging = false;
        event->accept();
    }
}

bool FloatingWidget::event(QEvent* event)
{
    if (event->type() == QEvent::ScreenChangeInternal) {
        // 屏幕切换时保持原尺寸不变
        return true;
    }
    return QWidget::event(event);
}


void FloatingWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        onDoubleClicked();
        event->accept();
    }
}

void FloatingWidget::onDoubleClicked()
{
    emit Start();
}