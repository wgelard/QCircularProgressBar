#include <QApplication>
#include <QCircularProgressBar.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCircularProgressBar *cpb = new QCircularProgressBar;
    cpb->setValue(75);
    cpb->show();

    return a.exec();
}
