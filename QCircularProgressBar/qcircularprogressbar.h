#ifndef QCIRCULARPROGRESSBAR_H
#define QCIRCULARPROGRESSBAR_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QFont>

#define MIN_SIZE 100
#define MARGIN 5

class QCircularProgressBar : public QWidget
{
    Q_OBJECT

public:
    QCircularProgressBar(QWidget *parent = 0);
    ~QCircularProgressBar();

//    void setValue(int value);

//    void setSize(int size);
//    void setColor(QColor color);
//    void setBackgrounColor(QColor color);
//    void setForegroundColor(QColor color);
//    void setBorderColor(QColor color);
//    void setTextColor(QColor color);

//    void enableGradientColor(bool enable);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_value;

    int m_size;
    QColor m_color;
    QColor m_backgroundColor;
    QColor m_foregroundColor;
    QColor m_borderColor;
    QColor m_textColor;

    int m_startAngle;
    int m_spanAngle;

    bool m_resizable;
    bool m_enable;
    QSize m_backgroundSize;



};

#endif // QCIRCULARPROGRESSBAR_H
