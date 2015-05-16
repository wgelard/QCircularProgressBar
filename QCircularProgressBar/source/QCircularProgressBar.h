#ifndef QCIRCULARPROGRESSBAR_H
#define QCIRCULARPROGRESSBAR_H

//!
//! \file QCircularProgressBar.h
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

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QFont>

#define MARGIN 5        //!< MARGIN Constant of the widget
#define MIN_SIZE 100    //!< MIN_SIZE Constant that define the minimum size of the widget
#define MIN_VALUE 0     //!< MIN_VALUE Constant of the minimum value allowed (0%)
#define MAX_VALUE 100   //!< MAX_VALUE Constant of the minimum value allowed (100%)


// Generation of the DLL
#if defined QCIRCULARPROGRESSBAR_LIBRARY
#define QCIRCULARPROGRESSBAR_EXPORT Q_DECL_EXPORT
#else
#define QCIRCULARPROGRESSBAR_EXPORT Q_DECL_IMPORT
#endif


/**
 * @class QCircularProgressBar
 * @brief The QCircularProgressBar class
 * allows to create a circular progress bar widget
 */
class QCIRCULARPROGRESSBAR_EXPORT QCircularProgressBar : public QWidget{
  Q_OBJECT

public:
  QCircularProgressBar(QWidget *parent = 0);
  ~QCircularProgressBar();

  void setProgressColor(const QColor &color);
  void setBacgroundProgressColor(const QColor &color);
  void setBackgrounColor(const QColor &color);
  void setForegroundColor(const QColor &color);
  void setBorderColor(const QColor &color);
  void setTextColor(const QColor &color);

  void enableGradientColor(const bool &enable);

public slots:
  void setValue(const int &value);

signals:
  void valueChange(int value);

protected:
  virtual void paintEvent(QPaintEvent *event);

private:
  int m_value;

  int m_size;
  QColor m_progressColor;
  QColor m_backgroundProgressColor;
  QColor m_backgroundColor;
  QColor m_foregroundColor;
  QColor m_borderColor;
  QColor m_textColor;

  int m_startAngle;
  int m_spanAngle;

  bool m_enableGradiant;
  QSize m_backgroundSize;

};

#endif // QCIRCULARPROGRESSBAR_H
