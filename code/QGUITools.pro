TEMPLATE = lib
DEFINES += QGUITOOLS_LIBRARY

QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT += core gui widgets

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    forms/qguidecimalselect.cpp \
    forms/qguiform.cpp \
    forms/qguiintselect.cpp \
    forms/qguiselect.cpp \
    qguicontainer.cpp \
    tabs/qguitab.cpp \
    windows/qguiwindow.cpp

HEADERS += \
    forms/qguidecimalselect.h \
    forms/qguiform.h \
    forms/qguiintervalselect.h \
    forms/qguiintselect.h \
    forms/qguiselect.h \
    qguicontainer.h \
    tabs/qguitab.h \
    windows/qguiwindow.h
