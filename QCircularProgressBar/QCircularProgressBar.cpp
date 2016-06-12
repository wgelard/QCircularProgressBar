//!
//! \file QCircularProgressBar.cpp
//! \author  William Gelard <gelard.william@gmail.com>
//! \version 1.0
//! \date April 2015
//!
//! \section LICENSE
//!
//! The MIT License (MIT)
//!
//! Copyright (c) 2015 William Gelard
//!
//! Permission is hereby granted, free of charge, to any person obtaining a copy
//! of this software and associated documentation files (the "Software"), to deal
//! in the Software without restriction, including without limitation the rights
//! to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//! copies of the Software, and to permit persons to whom the Software is
//! furnished to do so, subject to the following conditions:
//!
//! The above copyright notice and this permission notice shall be included in all
//! copies or substantial portions of the Software.
//!
//! THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//! IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//! FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//! AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//! LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//! OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//! SOFTWARE.
//!
//! \section DESCRIPTION
//!
//! The QCircularProgressBar class is a custom Qt Widget that allows to creat
//! circular progress bar.
//!

#include "../../QCircularProgressBar/QCircularProgressBar.h"

//!
//! \brief Construtor of the Class that initialize all the variables
//! and set the minimum size of the widget to the constant
//! value MIN_SIZE = 100
//! \param parent
//!
QCircularProgressBar::QCircularProgressBar(QCircularProgressBar::type type, QCircularProgressBar::style style, QWidget *parent)
    : QWidget(parent),
      m_type(type),
      m_style(style),
      m_value(0.0),

      m_size(MIN_SIZE-MARGIN*2),
      m_progressColor(QColor("royalblue")),
      m_backgroundProgressColor(QColor("#F0F0F0")),
      m_backgroundColor(Qt::white),
      m_foregroundColor(Qt::white),
      m_borderColor(Qt::darkGray),
      m_textColor(Qt::red),

      m_spanAngle(0),

      m_enableGradiant(true),

      m_backgroundSize(this->size())
{
    this->setMinimumSize(MIN_SIZE, MIN_SIZE);

    switch (m_type) {
    case arc:
        m_offsetAngle = 20;
        m_startAngle = ((270-m_offsetAngle)*16);
        m_fullSpanAngle = ((360-(m_offsetAngle*2))*16);
        m_endAngle = (-(m_fullSpanAngle - m_startAngle));
        break;

    case pie:
    default:
        m_offsetAngle = 0;
        m_startAngle = (90*16);
        m_fullSpanAngle = (360*16);
        m_endAngle = (-(m_fullSpanAngle - m_startAngle));
        break;
    }
}

//!
//! \brief Destructor of the Class
//!
QCircularProgressBar::~QCircularProgressBar(){}


//!
//! \brief Set the value of the progress bar
//! \param[in] value : The value of the progress bar
//! (Min value = 0, Max Value = 100)
//!
void QCircularProgressBar::setValue(const float &value){
    // Get the value
    m_value = value;

    // Verify MIN & MAX value
    if(m_value < MIN_VALUE){
        m_value = MIN_VALUE;
    }

    if(m_value > MAX_VALUE){
        m_value = MAX_VALUE;
    }

    // Compute angle
    switch (m_type) {
    case arc:
        m_spanAngle = ((value*m_fullSpanAngle/16.)*16/100.);
        break;
    case pie:
    default:
        m_spanAngle = ((value*360.)/100.)*16;
        break;
    }

    // Repaint the widget
    this->repaint();

    // Notify that the value has changed
    emit(valueChanged(m_value));
}

//!
//! \brief Set the color of the circular progress bar
//! \param[in] color : The color of the progress bar
//!
void QCircularProgressBar::setProgressColor(const QColor &color){
    m_progressColor = color;
    m_enableGradiant = false;
    this->repaint();
}

//!
//! \brief Set the color of the background of the circular progress bar
//! \param[in] color : The color of the background of the progress bar
//!
void QCircularProgressBar::setBacgroundProgressColor(const QColor &color){
    m_backgroundProgressColor = color;
    this->repaint();
}

//!
//! \brief Set the color of the background of the widget
//! \param[in] color : : The color of the background of the widget
//!
void QCircularProgressBar::setBackgrounColor(const QColor &color){
    m_backgroundColor = color;
    this->repaint();
}

//!
//! \brief Set the color of the foreground of the widget (text part)
//! \param[in] color : The color of the foreground
//!
void QCircularProgressBar::setForegroundColor(const QColor &color){
    m_foregroundColor = color;
    this->repaint();
}

//!
//! \brief Set the border color of the circular progress bar
//! \param[in] color : : The color of the border of the progress bar
//!
void QCircularProgressBar::setBorderColor(const QColor &color){
    m_borderColor = color;
    this->repaint();
}

//!
//! \brief Set the color of the text
//! \param[in] color : : The color of the text
//!
void QCircularProgressBar::setTextColor(const QColor &color){
    m_textColor = color;
    this->repaint();
}

//!
//! \brief Set the gradient color mode
//! \param[in] enable : True for enabling grandient color mode, False otherwise
//!
void QCircularProgressBar::enableGradientColor(const bool &enable){
    m_enableGradiant = enable;
    this->repaint();
}


QPointF QCircularProgressBar::getPosition(qreal angle, qreal distance)
{
    qreal x = distance*qCos(angle) + m_origin.x();
    qreal y = -distance*qSin(angle) + m_origin.y();

    return QPointF(x,y);
}


//!
//! \brief Paint the widget
//! \param event
//!
void QCircularProgressBar::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);

    this->setMinimumSize(MIN_SIZE, MIN_SIZE);

    // Creation of a painter
    QPainter painter(this);

    // Init background
    initProgressBar(painter);

    // Select type
    switch (m_type) {
    case arc:
        drawArc(painter);
        break;
    case pie:
    default:
        drawPie(painter);
        break;
    }

    // Draw text
    drawText(painter);
}

void QCircularProgressBar::initProgressBar(QPainter &painter){
    // Set Antialisation
    painter.setRenderHint(QPainter::Antialiasing);

    // Get the size of the widget
    m_backgroundSize = this->size();

    // Set the size of the circular progress bar
    if(m_backgroundSize.width() < m_backgroundSize.height()){
        m_size = m_backgroundSize.width() - MARGIN*2;
    }else{
        m_size = m_backgroundSize.height() - MARGIN*2;
    }

    // Make sure the circular progress bar stay visible without a magnifying glass ;D
    if(m_size < MIN_SIZE){
        m_size = MIN_SIZE-MARGIN*2;
    }

    // Set background color
    painter.setPen(Qt::NoPen);
    painter.setBrush(m_backgroundColor);
    painter.drawRect(0,0,m_backgroundSize.width(), m_backgroundSize.height());

    // Draw the circular background
    painter.setPen(m_borderColor.lighter(157));
    painter.setBrush(m_backgroundProgressColor);

    m_origin.setX(m_backgroundSize.width()/2);
    m_origin.setY(m_backgroundSize.height()/2);

    m_upperLeftCorner.setX(m_origin.x() - m_size/2);
    m_upperLeftCorner.setY(m_origin.y() - m_size/2);
}

void QCircularProgressBar::drawPie(QPainter &painter){

    painter.drawEllipse(QRectF(m_upperLeftCorner, QSize(m_size, m_size)));
    m_cg = QConicalGradient(m_origin,90);
    m_cg.setColorAt(0.0, Qt::red);
    m_cg.setColorAt(0.5, Qt::yellow);
    m_cg.setColorAt(1.0, Qt::green);

    //    m_cg.setColorAt(0.0, Qt::transparent);
    //    m_cg.setColorAt(0.5, Qt::transparent);
    //    m_cg.setColorAt(1.0, Qt::transparent);

    // Set the color of the circular progress bar
    if(m_enableGradiant){
        painter.setBrush(m_cg);
    }else{
        painter.setBrush(m_progressColor);
    }

    // Draw the progress bar
    painter.setPen(Qt::NoPen);

    painter.drawPie(QRectF(m_upperLeftCorner, QSize(m_size, m_size)).marginsRemoved(QMarginsF(1,1,1,1)), m_startAngle, -m_spanAngle);

    // Set the shadow effect of the foreground
    QLinearGradient g(QPointF((m_size/2.)+MARGIN,0.),QPointF((m_size/2.)+MARGIN,(m_size/2.)+MARGIN));
    g.setColorAt(0.0,Qt::transparent);
    g.setColorAt(1.0,m_borderColor);
    QPen p;
    p.setBrush(g);
    painter.setPen(p);

    // Draw the foreground
    painter.setBrush(m_foregroundColor);

    m_ratio = (2./3.)*m_size;
    painter.drawEllipse(m_origin, (int)(m_ratio/2.), (int)(m_ratio/2.));

    // Apply style
    if(m_style == style::round){
        drawRoundPie(painter);
    }
}

void QCircularProgressBar::drawArc(QPainter &painter){

    painter.drawPie(QRectF(m_upperLeftCorner, QSize(m_size, m_size)), m_startAngle, -m_fullSpanAngle);

    // Set the color of the circular progress bar
    m_cg = QConicalGradient(m_origin,270);
    m_cg.setColorAt(0.0, Qt::red);
    m_cg.setColorAt(0.5, Qt::yellow);
    m_cg.setColorAt(1.0, Qt::green);

    if(m_enableGradiant){
        painter.setBrush(m_cg);
    }else{
        painter.setBrush(m_progressColor);
    }

    // Draw the progress bar
    painter.setPen(Qt::NoPen);

    painter.drawPie(QRectF(m_upperLeftCorner, QSize(m_size, m_size)).marginsRemoved(QMargins(1,1,1,1)), m_startAngle, -m_spanAngle);
    painter.setPen(m_borderColor.lighter(157));

    // Draw the foreground
    painter.setBrush(m_foregroundColor);

    m_ratio = (3./4.)*m_size;
    painter.drawEllipse(m_origin, (int)(m_ratio/2.), (int)(m_ratio/2.));

    // Erase the bottom of the foregroound
    painter.setPen((Qt::NoPen));
    painter.drawPie(QRectF(m_upperLeftCorner, QSize(m_size, m_size)), m_startAngle+2, (m_offsetAngle*2)*16 - 4);

    // Apply style
    if(m_style == style::round){
        drawRoundArc(painter);
    }
}


void QCircularProgressBar::drawText(QPainter &painter){
    // Draw text in a rectangle
    m_x = m_origin.x() - m_ratio/2. + 2*MARGIN;
    m_y = m_origin.y() - m_ratio/4.;

    QRectF rect = QRectF(m_x, m_y, m_ratio-4*MARGIN, m_ratio/2.);

    // Set font
    QFont font;
    font.setPixelSize( rect.height()/2.5);
    painter.setFont( font );

    // Draw text
    painter.setPen(m_textColor);
    painter.drawText( rect, Qt::AlignCenter, QString("%1%").arg(QString::number(m_value, 'f', 2)));
}

void QCircularProgressBar::drawRoundArc(QPainter &painter){
    qreal ellispseRaduis = (m_size - m_ratio)/4;
    qreal dist = (m_ratio/2 + ellispseRaduis) - 0.5;

    // Draw first ellipse
    painter.setPen(Qt::NoPen);
    if(m_value == 0){
        painter.setBrush(m_backgroundProgressColor);
    }else{
        if(m_enableGradiant){
            painter.setBrush(m_cg);
        }else{
            painter.setBrush(m_progressColor);
        }
    }

    QPointF pos = getPosition(qDegreesToRadians((float)m_startAngle/16.),  dist);
    painter.drawEllipse(pos, ellispseRaduis, ellispseRaduis);
    painter.setPen(m_borderColor.lighter(157));
    painter.drawArc(QRectF(pos.x()-ellispseRaduis+0.5, pos.y()-ellispseRaduis+0.5, ellispseRaduis*2  - 1 ,2*ellispseRaduis  - 1) ,m_startAngle, 180*16);

    // Draw last ellipse
    painter.setPen(Qt::NoPen);
    if(m_value == 100){
        if(m_enableGradiant){
            painter.setBrush(m_cg);
        }else{
            painter.setBrush(m_progressColor);
        }
    }else{
        painter.setBrush(m_backgroundProgressColor);
    }

    pos = getPosition(qDegreesToRadians((float)m_endAngle/16.),  dist);
    painter.drawEllipse(pos, ellispseRaduis, ellispseRaduis);
    painter.setPen(m_borderColor.lighter(157));
    painter.drawArc(QRectF(pos.x()-ellispseRaduis+0.5, pos.y()-ellispseRaduis+0.5, ellispseRaduis*2  - 1 ,2*ellispseRaduis  - 1) ,m_endAngle, -180*16);

    // Draw intermediare ellipse
    if(m_value > 0 && m_value < 100){
        int angle =(m_startAngle - m_spanAngle);

        pos = getPosition(qDegreesToRadians((float)angle/16.),  dist);

        painter.setPen(Qt::NoPen);
        if(m_enableGradiant){
            painter.setBrush(m_cg);
        }else{
            painter.setBrush(m_progressColor);
        }
        painter.drawEllipse(pos, ellispseRaduis, ellispseRaduis);
    }
}

void QCircularProgressBar::drawRoundPie(QPainter &painter){
    qreal ellispseRaduis = (m_size - m_ratio)/4;
    qreal dist = (m_ratio/2 + ellispseRaduis) - 0.5;

    QPointF pos;

    // Draw last ellipse
    painter.setPen(Qt::NoPen);
    if(m_value > 0.0 && m_value < 100.0){
        if(m_enableGradiant){
            painter.setBrush(m_cg);
        }else{
            painter.setBrush(m_progressColor);
        }
        int angle =(m_startAngle - m_spanAngle);
        pos = getPosition(qDegreesToRadians((float)angle/16.),  dist);
        painter.drawEllipse(pos, ellispseRaduis, ellispseRaduis);
        painter.setPen(m_borderColor.lighter(157));
        painter.drawArc(QRectF(pos.x()-ellispseRaduis+0.5, pos.y()-ellispseRaduis+0.5, ellispseRaduis*2  - 1 ,2*ellispseRaduis  - 1) ,angle, -180*16);
    }


    // Draw first ellipse
    painter.setPen(Qt::NoPen);
    if(m_value > 0.0){
        if(m_enableGradiant){

            QConicalGradient cg = QConicalGradient(m_origin,90);
            cg.setColorAt(0.0, Qt::green);
            cg.setColorAt(0.5, Qt::yellow);
            cg.setColorAt(1.0, Qt::green);

            painter.setBrush(cg);
        }else{
            painter.setBrush(m_progressColor);
        }

        pos = getPosition(qDegreesToRadians((float)m_startAngle/16.),  dist);
        painter.drawEllipse(pos, ellispseRaduis, ellispseRaduis);

    }

}
