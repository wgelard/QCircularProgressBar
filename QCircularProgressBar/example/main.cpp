#include <QApplication>
#include "example.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    example p;
    p.show();

    return a.exec();
}
