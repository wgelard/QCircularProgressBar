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
#include <QTimer>

#include "../../QCircularProgressBar/QCircularProgressBar.h"

class CustomCircularProgressBar : public QWidget
{
  Q_OBJECT

public:
  CustomCircularProgressBar();
  ~CustomCircularProgressBar();

private:
  QHBoxLayout *m_layout;

  QCircularProgressBar *m_progress_1;
  QCircularProgressBar *m_progress_2;
  QCircularProgressBar *m_progress_3;

  QTimer *m_timer_1;
  QTimer *m_timer_2;
  QTimer *m_timer_3;

  bool m_up1, m_up2, m_up3;
  int m_val1, m_val2, m_val3;

private slots:
  void updateProgress1();
  void updateProgress2();
  void updateProgress3();
};

#endif // CUSTOMCIRCULARPROGRESSBAR_H
