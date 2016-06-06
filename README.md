# QCircularProgressBar v1.0
----------------------------
The **QCircularProgressBar** is a QtWidget developped in order to get a new style of QProgressBar, a circular progress bar inspired by [QtKnobs](https://github.com/ashish157/QtKnobs), Qt and QML based Library/Plugin which provides different types of Knobs.


## Current version
Version: 1.0

Autor  : William Gélard

Date   : April 2015


## Usage
* All you have to do is to donwload the library, compile it and enjoy ;p

```
$ git clone https://github.com/Wiwi-31/QCircularProgressBar.git
```

## Example Code
* This few lines below gives the simplest way to display a QProgressBar

```cpp
#include <QApplication>
#include <QCircularProgressBar.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCircularProgressBar cpb;
    cpb.setValue(75);
    cpb.show();

    return a.exec();
}
```


* A simple QProgressBar

![alt text](screenshots/simple.PNG "A simple QProgessBar")

## List of property
This Widget is completly customizable and you can change all the color:
* Enable/disable gradient color
* Progress bar color
* Background progress color
* Foreground color
* Border color
* Text color

### Notes
* The QCircularProgressBar inherit from QtWidget, so you can use the QtWidget methods.

## Example
* An example is availabe in the folder **QCircularProgressBar/example**

### ScreenShots
* Basic QCircularProgressBar

![alt text](screenshots/basic.PNG "A basic QProgessBar")

* Resizable QCircularProgressBar

![alt text](screenshots/resizable.PNG "A resizable QProgessBar")

* A simple color QCircularProgressBar

![alt text](screenshots/basicColor.PNG "A simple color QProgessBar")

* A total customizable QProgressBar

![alt text](screenshots/custom.PNG "Wow! That's awfull")

## License

MIT

## Contact
* Email: gelard.william@gmail.com

*Note:* ***Please use the GitHub issues*** *for questions and problems regarding the QCircularProgressBar project.* ***Do not write emails.***
