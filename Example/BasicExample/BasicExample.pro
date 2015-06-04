#-------------------------------------------------
#
# Project created by QtCreator 2015-06-04T22:17:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BasicExample
TEMPLATE = app

DEPENDPATH += ../../QCircularProgressBar/include
INCLUDEPATH += ../../QCircularProgressBar/include

CONFIG += release

LIBS += -L../../lib -lQCircularProgressBar

SOURCES += main.cpp
