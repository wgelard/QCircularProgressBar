#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T15:09:41
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Example
TEMPLATE = app

DEPENDPATH += ../QCircularProgressBar/include
INCLUDEPATH += ../QCircularProgressBar/include

CONFIG(debug, debug|release) {
    LIBS += -L../lib -lQCircularProgressBard
}else{
    LIBS += -L../lib -lQCircularProgressBar
}

SOURCES += main.cpp \
    widgetexample.cpp

HEADERS += \
    widgetexample.h
