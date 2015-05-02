#include "qcircularprogressbar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCircularProgressBar w;
    w.setValue(90);
    w.enableGradientColor(true);
//    w.setResizable(false);
//    w.setMaximumSize(200,200);
//    w.setProgressColor(Qt::blue);
//    w.setBacgroundProgressColor(Qt::magenta);
//    w.setBackgrounColor(Qt::red);
//    w.setForegroundColor(Qt::green);
//    w.setTextColor(Qt::yellow);
//    w.setBorderColor(Qt::darkCyan);
    w.show();

    return a.exec();
}
