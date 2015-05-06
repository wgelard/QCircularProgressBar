# QCircularProgressBar v1.0
Autor: William Gelard
Date : April 2015
mail : gelard.william@gmail.com

## Abstract
The QCircularProgressBar is a QtWidget developped in order to get a new style of QProgressBar, a circular progress bar.

## Installation
All you have to do is to donwload .h and .cpp files, add this files to your project and enjoy !

### Procedure
- Dowload the following files
 - QCircularProgressBar.h
 - QCircularProgressBar.cpp
- Add them to your project
- That's it !

## Example Code
This few lines below gives the simplest way to display a QProgressBar

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

![alt text](screenshots/simple.PNG "A simple QProgessBar")

