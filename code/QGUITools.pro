TEMPLATE = lib
DEFINES += QGUITOOLS_LIBRARY

QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT += core gui widgets

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    forms/dropdown/qguidecimaldropdown.cpp \
    forms/dropdown/qguidropdown.cpp \
    forms/dropdown/qguiintdropdown.cpp \
    forms/text/qguitext.cpp \
    forms/qguiform.cpp \
    qguicontainer.cpp \
    tabs/qguitab.cpp \
    windows/qguiwindow.cpp

HEADERS += \
    forms/dropdown/qguidecimaldropdown.h \
    forms/dropdown/qguidropdown.h \
    forms/dropdown/qguiintdropdown.h \
    forms/dropdown/qguiintervaldropdown.h \
    forms/text/qguitext.h \
    forms/qguiform.h \
    qguicontainer.h \
    tabs/qguitab.h \
    windows/qguiwindow.h
