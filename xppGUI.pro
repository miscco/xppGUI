#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T15:27:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = xppaut_GUI
TEMPLATE = app

include(GUI/qcustomplot/QCustomPlot.pri)

SOURCES	 += main.cpp \
	    xppCore.cpp \
	    GUI/xppAutoWindow.cpp \
	    GUI/xppMainWindow.cpp \
	    GUI/xppMenuButton.cpp \
	    GUI/xppMenuDialog.cpp \
	    GUI/xppMenuLabels.cpp

HEADERS  += xppColor.h		\
	    xppCore.h		\
	    xppCoreDefines.h	\
	    xppPlots.h		\
	    GUI/xppAutoWindow.h \
	    GUI/xppMainWindow.h \
	    GUI/xppMenuButton.h \
	    GUI/xppMenuDialog.h \
	    GUI/xppMenuLabels.h

FORMS    += GUI/xppMainWindow.ui \
	    GUI/xppAutoWindow.ui

INCLUDEPATH += GUI

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS -= -O1
QMAKE_CXXFLAGS -= -O2
QMAKE_CXXFLAGS *= -O3

OTHER_FILES +=
