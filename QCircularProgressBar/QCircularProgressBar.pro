#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T14:30:25
#
#-------------------------------------------------

QT       += widgets

CONFIG += debug_and_release
CONFIG += build_all

CONFIG(debug, debug|release) {
    TARGET = QCircularProgressBard
}else{
    TARGET = QCircularProgressBar
}

TEMPLATE = lib

SOURCES += \
    src/QCircularProgressBar.cpp

HEADERS  += \
    include/QCircularProgressBar.h

DEFINES += QCIRCULARPROGRESSBAR_LIBRARY

DESTDIR = ../lib


#DEPENDPATH += ../../QCircularProgressBar/include
#INCLUDEPATH += ../../QCircularProgressBar/include

#CONFIG += release

##CONFIG(debug, debug|release) {
##    LIBS += -L../lib -lQCircularProgressBard
##}else{
#    LIBS += -L../../lib -lQCircularProgressBar
##}
