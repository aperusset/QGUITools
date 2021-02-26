TEMPLATE = lib
DEFINES += QGUITOOLS_LIBRARY

QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT -= gui
QT += core widgets

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    forms/dropdown/decimaldropdown.cpp \
    forms/dropdown/dropdown.cpp \
    forms/dropdown/integerdropdown.cpp \
    forms/qguiform.cpp \
    forms/text/text.cpp \
    qguicontainer.cpp \
    tabs/qguitab.cpp \
    windows/qguiwindow.cpp

HEADERS += \
    forms/dropdown/decimaldropdown.h \
    forms/dropdown/dropdown.h \
    forms/dropdown/integerdropdown.h \
    forms/dropdown/intervaldropdown.h \
    forms/qguiform.h \
    forms/text/text.h \
    qguicontainer.h \
    tabs/qguitab.h \
    windows/qguiwindow.h
