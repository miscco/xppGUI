#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T15:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = xppaut_GUI
TEMPLATE = app

include(qcustomplot/QCustomPlot.pri)

SOURCES	 += main.cpp\
			mainwindow.cpp \
			autowindow.cpp \
    xppMenuLabels.cpp \
    xppMenuButton.cpp \
    xppMenuDialog.cpp

HEADERS  += mainwindow.h \
			autowindow.h \
    xppMenuLabels.h \
    xppMenuButton.h \
    xppMenuDialog.h

FORMS    += mainwindow.ui \
			autowindow.ui

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES +=
