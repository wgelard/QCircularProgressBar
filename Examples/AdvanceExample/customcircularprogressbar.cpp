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

#include "customcircularprogressbar.h"

CustomCircularProgressBar::CustomCircularProgressBar() : QWidget(), m_val1(0)//, m_val2(0), m_val3(0)
{
  m_layout = new QHBoxLayout;

  m_progress_1 = new QCircularProgressBar(QCircularProgressBar::type::arc, QCircularProgressBar::style::round);
  m_progress_1->setFixedSize(150, 150);

  m_progress_2 = new QCircularProgressBar(QCircularProgressBar::type::pie, QCircularProgressBar::style::round);
  m_progress_2->setFixedSize(100, 100);
  m_progress_2->enableGradientColor(false);


  m_progress_3 = new QCircularProgressBar;
  m_progress_3->setBacgroundProgressColor(Qt::red);
  m_progress_3->setProgressColor(Qt::green);
  m_progress_3->setForegroundColor(Qt::blue);
  m_progress_3->setTextColor(Qt::magenta);
  m_progress_3->setBorderColor(Qt::darkBlue);

  m_layout->addWidget(m_progress_1,0,Qt::AlignTop);
  m_layout->addWidget(m_progress_2,0,Qt::AlignTop);
  m_layout->addWidget(m_progress_3);

  this->setStyleSheet("QWidget {background-color: white;}");
  setLayout(m_layout);

  m_timer_1 = new QTimer;
//  m_timer_2 = new QTimer;
//  m_timer_3 = new QTimer;

  QObject::connect(m_timer_1, SIGNAL(timeout()), this, SLOT(updateProgress1()));
//  QObject::connect(m_timer_2, SIGNAL(timeout()), this, SLOT(updateProgress2()));
//  QObject::connect(m_timer_3, SIGNAL(timeout()), this, SLOT(updateProgress3()));

  m_timer_1->start(10);
//  m_timer_2->start(100);
//  m_timer_3->start(100);

  m_up1 = true;
//  m_up2 = true;
//  m_up3 = true;

}

CustomCircularProgressBar::~CustomCircularProgressBar()
{
  delete m_progress_1;
  delete m_progress_2;
  delete m_progress_3;

  delete m_layout;

  m_timer_1->stop();/*
  m_timer_2->stop();
  m_timer_3->stop();*/

  delete m_timer_1;
//  delete m_timer_2;
//  delete m_timer_3;
}

void CustomCircularProgressBar::updateProgress1(){
    if(m_up1){
        m_val1+= 0.1;
        if(m_val1 >= 100)
            m_up1 = false;
    }else{
        m_val1-= 0.1;
        if(m_val1 <= 0)
            m_up1 = true;
    }

    m_progress_1->setValue(m_val1);
    m_progress_2->setValue(m_val1);
    m_progress_3->setValue(m_val1);
}

//void CustomCircularProgressBar::updateProgress2(){
//    if(m_up2){
//        m_val2++;
//        if(m_val2 >= 100)
//            m_up2 = false;
//    }else{
//        m_val2--;
//        if(m_val2 <= 0)
//            m_up2 = true;
//    }

//    m_progress_2->setValue(m_val2);
//}

//void CustomCircularProgressBar::updateProgress3(){
//    if(m_up3){
//        m_val3++;
//        if(m_val3 >= 100)
//            m_up3 = false;
//    }else{
//        m_val3--;
//        if(m_val3 <= 0)
//            m_up3 = true;
//    }

//    m_progress_3->setValue(m_val3);
//}
