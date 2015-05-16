#ifndef WIDGETEXAMPLE_H
#define WIDGETEXAMPLE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QCircularProgressBar.h>

class WidgetExample : public QWidget
{
  Q_OBJECT
public:
  WidgetExample();
  ~WidgetExample();

  QCircularProgressBar *cpb;

public slots:
};

#endif // WIDGETEXAMPLE_H
