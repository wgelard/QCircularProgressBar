#include <QApplication>
#include "widgetexample.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  WidgetExample we;
  we.show();

  return a.exec();
}
