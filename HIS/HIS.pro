#-------------------------------------------------
#
# Project created by QtCreator 2016-04-12T10:30:17
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HIS
TEMPLATE = app


SOURCES += main.cpp\
        hismainwindow.cpp \
    cliniccharge.cpp \
    clinicdailyreport.cpp \
    subform.cpp

HEADERS  += hismainwindow.h \
    cliniccharge.h \
    stdafx.h \
    connectDB.h \
    clinicdailyreport.h \
    subform.h \
    winSet.h

FORMS    += hismainwindow.ui \
    cliniccharge.ui \
    clinicdailyreport.ui \
    subform.ui

OTHER_FILES +=

RESOURCES +=
