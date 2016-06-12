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

#ifndef CUSTOMCIRCULARPROGRESSBAR_H
#define CUSTOMCIRCULARPROGRESSBAR_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

#include "../../QCircularProgressBar/QCircularProgressBar.h"

class CustomCircularProgressBar : public QWidget{
    Q_OBJECT

public:
    CustomCircularProgressBar();
    ~CustomCircularProgressBar();

private:
    QVBoxLayout*m_layout;
    QHBoxLayout *m_firstRow, *m_secondRow, *m_thirdRow;

    QLabel *m_label1, *m_label2, *m_label3, *m_label4;

    QCircularProgressBar *m_progress_1;
    QCircularProgressBar *m_progress_2;
    QCircularProgressBar *m_progress_3;
    QCircularProgressBar *m_progress_4;

    QCircularProgressBar *m_progress_5;
    QCircularProgressBar *m_progress_6;
    QCircularProgressBar *m_progress_7;
    QCircularProgressBar *m_progress_8;

    QTimer *m_timer;

    bool m_up;
    float m_val;

private slots:
    void updateProgress();
};

#endif // CUSTOMCIRCULARPROGRESSBAR_H
