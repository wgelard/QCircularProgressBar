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

CustomCircularProgressBar::CustomCircularProgressBar() : QWidget(), m_val(0){
    m_layout = new QVBoxLayout;

    m_firstRow = new QHBoxLayout;
    m_secondRow = new QHBoxLayout;
    m_thirdRow = new QHBoxLayout;

    // ---------------------- Label ----------------------
    m_label1 = new QLabel("Pie type - Flat style");
    m_label2 = new QLabel("Pie type - Round style");
    m_label3 = new QLabel("Arc type - Flat style");
    m_label4 = new QLabel("Arc type - Round style");

    // ---------- Default Circular Progress Bar ----------
    // Default Circular Progress bar: Pie type, Flat style
    m_progress_1 = new QCircularProgressBar();

    // Pie type, Round style
    m_progress_2 = new QCircularProgressBar(QCircularProgressBar::type::pie, QCircularProgressBar::style::round);

    // Arc type, Flat style
    m_progress_3 = new QCircularProgressBar(QCircularProgressBar::type::arc);

    // Arc type, Round style
    m_progress_4 = new QCircularProgressBar(QCircularProgressBar::type::arc, QCircularProgressBar::style::round);


    // ---------- Custom Circular Progress Bar ----------
    // Default Circular Progress bar: Pie type, Flat style
    m_progress_5 = new QCircularProgressBar();
    // Disable gradient mode
    m_progress_5->enableGradientColor(false);

    // Pie type, Round style
    m_progress_6 = new QCircularProgressBar(QCircularProgressBar::type::pie, QCircularProgressBar::style::round);
    // Disable gradient mode and change de default color
    // Disable gradient mode and change de default progress color
    m_progress_6->setProgressColor("#35a79c");
    // Change dafault background progress color
    m_progress_6->setBacgroundProgressColor("#83d0c9");
    // Disable gradient mode and change de default progress color
    m_progress_6->setBackgrounColor("#009688"); // If arc type --> forground = background
    //    m_progress_8->setForegroundColor("#009688"); // If arc type --> background = forground ==> idem
    // Change default text color
    m_progress_6->setTextColor("#54b2a9");

    // Arc type, Flat style
    m_progress_7 = new QCircularProgressBar(QCircularProgressBar::type::arc);
    // Disable gradient mode
    m_progress_7->enableGradientColor(false);

    // Arc type, Round style
    m_progress_8 = new QCircularProgressBar(QCircularProgressBar::type::arc, QCircularProgressBar::style::round);
    // Disable gradient mode and change de default progress color
    m_progress_8->setProgressColor("#35a79c");
    // Change dafault background progress color
    m_progress_8->setBacgroundProgressColor("#83d0c9");
    // Disable gradient mode and change de default progress color
    m_progress_8->setBackgrounColor("#009688"); // If arc type --> forground = background
    //    m_progress_8->setForegroundColor("#009688"); // If arc type --> background = forground ==> idem
    // Change default text color
    m_progress_8->setTextColor("#54b2a9");

    m_firstRow->addWidget(m_label1, 0, Qt::AlignHCenter);
    m_firstRow->addWidget(m_label2, 0, Qt::AlignHCenter);
    m_firstRow->addWidget(m_label3, 0, Qt::AlignHCenter);
    m_firstRow->addWidget(m_label4, 0, Qt::AlignHCenter);

    m_secondRow->addWidget(m_progress_1);
    m_secondRow->addWidget(m_progress_2);
    m_secondRow->addWidget(m_progress_3);
    m_secondRow->addWidget(m_progress_4);

    m_thirdRow->addWidget(m_progress_5);
    m_thirdRow->addWidget(m_progress_6);
    m_thirdRow->addWidget(m_progress_7);
    m_thirdRow->addWidget(m_progress_8);

    m_layout->addLayout(m_firstRow,0);
    m_layout->addLayout(m_secondRow,1);
    m_layout->addLayout(m_thirdRow,1);

    this->setStyleSheet("QWidget {background-color: white;}");
    setLayout(m_layout);

    m_timer = new QTimer;

    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(updateProgress()));

    m_timer->start(10);

    m_up = true;
}

CustomCircularProgressBar::~CustomCircularProgressBar(){
    delete m_progress_1;
    delete m_progress_2;
    delete m_progress_3;
    delete m_progress_4;
    delete m_progress_5;

    delete m_layout;

    m_timer->stop();

    delete m_timer;
}

void CustomCircularProgressBar::updateProgress(){
    if(m_up){
        m_val+= 0.1;
        if(m_val >= 100)
            m_up = false;
    }else{
        m_val-= 0.1;
        if(m_val <= 0)
            m_up = true;
    }

    m_progress_1->setValue(m_val);
    m_progress_2->setValue(m_val);
    m_progress_3->setValue(m_val);
    m_progress_4->setValue(m_val);

    m_progress_5->setValue(m_val);
    m_progress_6->setValue(m_val);
    m_progress_7->setValue(m_val);
    m_progress_8->setValue(m_val);
}
