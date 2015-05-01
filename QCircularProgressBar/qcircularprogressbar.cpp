#include "qcircularprogressbar.h"

QCircularProgressBar::QCircularProgressBar(QWidget *parent)
    : QWidget(parent),
      m_value(0),

      m_size(MIN_SIZE-MARGIN*2),
      m_color(QColor(100,100,100)),
      m_backgroundColor(Qt::white),
      m_foregroundColor(QColor(240, 240, 240)),
      m_borderColor(Qt::darkGray),
      m_textColor(Qt::lightGray),

      m_startAngle(90*16),
      m_spanAngle(0),

      m_resizable(true),
      m_enable(false),

      m_backgroundSize(this->size())
{
    this->setMinimumSize(MIN_SIZE, MIN_SIZE);
}

QCircularProgressBar::~QCircularProgressBar()
{

}

void QCircularProgressBar::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::NoPen);
    painter.setBrush(m_backgroundColor);
    m_backgroundSize = this->size();

    if(m_resizable){
        if(m_backgroundSize.width() < m_backgroundSize.height()){
            m_size = m_backgroundSize.width() - MARGIN*2;
        }else{
            m_size = m_backgroundSize.height() - MARGIN*2;
        }
    }

    painter.drawRect(0,0,m_backgroundSize.width(), m_backgroundSize.height());

    QColor m_borderColor = Qt::darkGray;

    painter.setPen(m_borderColor.lighter(157));
    painter.setBrush(m_foregroundColor);
    painter.drawEllipse(QRectF(MARGIN,MARGIN,m_size,m_size));

    painter.setPen(Qt::NoPen);

    if(!m_enable){
        painter.setBrush(m_color);
    }else{
        QConicalGradient cg(QPointF((m_size/2.0)+MARGIN,(m_size/2)+MARGIN),90);
        cg.setColorAt(0.0, Qt::red);
        cg.setColorAt(0.5, Qt::yellow);
        cg.setColorAt(1.0, Qt::green);
        painter.setBrush(cg);
    }

    painter.drawPie(QRectF(MARGIN, MARGIN, m_size, m_size).marginsRemoved(QMarginsF(MARGIN, MARGIN, MARGIN, MARGIN)), m_startAngle, -m_spanAngle);

    QLinearGradient g(QPointF((m_size/2.)+MARGIN,0.),QPointF((m_size/2.)+MARGIN,(m_size/2.)+MARGIN));
    g.setColorAt(0.0,Qt::transparent);
    g.setColorAt(1.0,m_borderColor);
    QPen p;
    p.setBrush(g);
    painter.setPen(p);
    painter.setBrush(Qt::white);

    float ratio = (2./3.)*m_size;
    painter.drawEllipse(QPointF((m_size/2.0)+MARGIN,(m_size/2)+MARGIN), ratio/2., ratio/2.);

    QRectF rect = QRectF(((m_size-ratio)/2.)+MARGIN, ((m_size-(ratio/2.))/2.)+MARGIN, ratio, (ratio/2.));
    painter.setBrush(m_textColor);
    QFont font;
    font.setPixelSize( rect.height()/2 );
    painter.setFont( font );
    painter.drawText( rect, Qt::AlignCenter, QString("%1%").arg((m_value)) );
}
