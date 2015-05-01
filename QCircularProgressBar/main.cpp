#include "qcircularprogressbar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCircularProgressBar w;
    w.show();

    return a.exec();
}
