TEMPLATE = lib
DEFINES += QGUITOOLS_LIBRARY

QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT += core gui widgets

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    forms/qguiform.cpp \
    qguicontainer.cpp \
    tabs/qguitab.cpp \
    windows/qguiwindow.cpp

HEADERS += \
    forms/qguiform.h \
    qguicontainer.h \
    tabs/qguitab.h \
    windows/qguiwindow.h
