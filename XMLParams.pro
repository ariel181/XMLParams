#-------------------------------------------------
#
# Project created by QtCreator 2018-03-06T21:40:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XMLParams
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    enumfeature.cpp \
    featureupdater.cpp \
    feature.cpp \
    featureinfo.cpp \
    featurebuilder.cpp \
    intfeature.cpp \
    boolfeature.cpp \
    featurecontainer.cpp \
    gropefeature.cpp \
    basefeature.cpp \
    featuretreemodel.cpp \
    paramerers.cpp

HEADERS  += mainwindow.h \
    feature.h \
    enumfeature.h \
    featureupdater.h \
    intfeature.h \
    boolfeature.h \
    featurecontainer.h \
    featureinfo.h \
    basefeature.h \
    gropefeature.h \
    featurebuilder.h \
    featuretreemodel.h \
    sharedpointerdefines.h \
    errortype.h \
    paramerers.h

FORMS    += mainwindow.ui

SUBDIRS += \
    parametars.pro
