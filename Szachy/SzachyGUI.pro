#-------------------------------------------------
#
# Project created by QtCreator 2020-05-01T16:08:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SzachyGUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        bierka.cpp \
        pion.cpp \
        szachownica.cpp \
        goniec.cpp \
        kon.cpp \
        hetman.cpp \
        wieza.cpp \
        krol.cpp \
        rozgrywka.cpp \
    promocja.cpp \
    poprzedniruch.cpp \
    plansza.cpp

HEADERS  += mainwindow.h\
        bierka.h \
        pion.h \
        szachownica.h \
        goniec.h \
        kon.h \
        hetman.h \
        wieza.h \
        krol.h \
        rozgrywka.h \
    promocja.h \
    poprzedniruch.h \
    plansza.h

FORMS    += mainwindow.ui \
    promocja.ui

RESOURCES += \
    figury.qrc

