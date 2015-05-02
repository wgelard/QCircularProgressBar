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
#include "qcircularprogressbar.h"

//!
//! \brief Construtor of the Class that initialize all the variables
//! and set the minimum size of the widget to the constant
//! value MIN_SIZE = 100
//! \param parent
//!
QCircularProgressBar::QCircularProgressBar(QWidget *parent)
    : QWidget(parent),
      m_value(0),

      m_size(MIN_SIZE-MARGIN*2),
      m_progressColor(Qt::darkGreen),
      m_backgroundProgressColor(QColor(240, 240, 240)),
      m_backgroundColor(Qt::white),
      m_foregroundColor(Qt::white),
      m_borderColor(Qt::darkGray),
      m_textColor(Qt::darkGray),

      m_startAngle(90*16),
      m_spanAngle(0),

      m_enableGradiant(false),

      m_backgroundSize(this->size())
{
    this->setMinimumSize(MIN_SIZE, MIN_SIZE);
}

//!
//! \brief Destructor of the Class
//!
QCircularProgressBar::~QCircularProgressBar(){}

//!
//! \brief Paint the widget
//! \param event
//!
void QCircularProgressBar::paintEvent(QPaintEvent *event){
    // Creation of a painter
    QPainter painter(this);

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
    painter.drawEllipse(QRectF(MARGIN,MARGIN,m_size,m_size));


    // Set the color of the circular progress bar
    if(m_enableGradiant){
        QConicalGradient cg(QPointF((m_size/2.0)+MARGIN,(m_size/2)+MARGIN),90);
        cg.setColorAt(0.0, Qt::red);
        cg.setColorAt(0.5, Qt::yellow);
        cg.setColorAt(1.0, Qt::green);
        painter.setBrush(cg);
    }else{
        painter.setBrush(m_progressColor);
    }

    // Draw the progress bar
    painter.setPen(Qt::NoPen);
    painter.drawPie(QRectF(MARGIN, MARGIN, m_size, m_size).marginsRemoved(QMarginsF(1,1,1,1)), m_startAngle, -m_spanAngle);

    // Set the shadow effect of the foreground
    QLinearGradient g(QPointF((m_size/2.)+MARGIN,0.),QPointF((m_size/2.)+MARGIN,(m_size/2.)+MARGIN));
    g.setColorAt(0.0,Qt::transparent);
    g.setColorAt(1.0,m_borderColor);
    QPen p;
    p.setBrush(g);

    // Draw the foreground
    painter.setPen(p);
    painter.setBrush(m_foregroundColor);

    // I think 2/3 | 1/3 is a good ratio
    float ratio = (2./3.)*m_size;
    painter.drawEllipse(QPointF((m_size/2.0)+MARGIN,(m_size/2)+MARGIN), ratio/2., ratio/2.);

    // Draw text in a rectangle
    QRectF rect = QRectF(((m_size-ratio)/2.)+MARGIN, ((m_size-(ratio/2.))/2.)+MARGIN, ratio, (ratio/2.));

    // Set font
    QFont font;
    font.setPixelSize( rect.height()/2 );
    painter.setFont( font );

    // Draw text
    painter.setPen(m_textColor);
    painter.drawText( rect, Qt::AlignCenter, QString("%1%").arg((m_value)) );
}

//!
//! \brief Set the value of the progress bar
//! \param[in] value : The value of the progress bar
//! (Min value = 0, Max Value = 100)
//!
void QCircularProgressBar::setValue(const int &value){
    m_value = value;

    if(m_value < MIN_VALUE){
        m_value = MIN_VALUE;
    }

    if(m_value > MAX_VALUE){
        m_value = MAX_VALUE;
    }

    m_spanAngle = ((value*360.)/100.)*16;
    this->repaint();
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
