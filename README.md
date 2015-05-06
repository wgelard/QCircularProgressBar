Abstract:
---------
This project is an Qt project to create a new custom widget: QCircularProgressBa

Autor: William Gelard

Date : April 2015

mail : gelard.william@gmail.com

```cpp
#include <QApplication>
#include "QCircularProgressBar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCircularProgressBar cpb;
    cpb.setValue(75);
    cpb.show();

    return a.exec();
}
```
