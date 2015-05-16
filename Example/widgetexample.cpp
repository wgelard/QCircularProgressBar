#include "widgetexample.h"
#include <QCircularProgressBar.h>

WidgetExample::WidgetExample() : QWidget(){

  cpb = new QCircularProgressBar();
  cpb->setValue(75);

  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(cpb);
  this->setLayout(layout);
}

WidgetExample::~WidgetExample(){
  delete cpb;
}
