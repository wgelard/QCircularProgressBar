#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T14:30:25
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += debug_and_release
CONFIG += build_all

CONFIG(debug, debug|release) {
    TARGET = QCircularProgressBard
}else{
    TARGET = QCircularProgressBar
}

TEMPLATE = lib

SOURCES += \
    source/QCircularProgressBar.cpp

HEADERS  += \
    source/QCircularProgressBar.h

DEFINES += QCIRCULARPROGRESSBAR_LIBRARY

DESTDIR = ../lib
