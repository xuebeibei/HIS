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
    subform.cpp \
    histable.cpp \
    persion.cpp \
    patient.cpp \
    clinicchargetable.cpp \
    clinicchargeitem.cpp \
    findclincchargedlg.cpp

HEADERS  += hismainwindow.h \
    cliniccharge.h \
    stdafx.h \
    clinicdailyreport.h \
    subform.h \
    winSet.h \
    histable.h \
    persion.h \
    patient.h \
    clinicchargetable.h \
    connectDB.h \
    clinicchargeitem.h \
    findclincchargedlg.h

FORMS    += hismainwindow.ui \
    cliniccharge.ui \
    clinicdailyreport.ui \
    subform.ui \
    findclincchargedlg.ui

OTHER_FILES +=

RESOURCES +=
