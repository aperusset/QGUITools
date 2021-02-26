QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT += testlib widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    fixture/testdropdown.h \
    fixture/testform.h \
    forms/dropdown/dropdowntest.h \
    forms/dropdown/intervaldropdowntest.h \
    forms/qguiformtest.h

SOURCES += \
    forms/dropdown/dropdowntest.cpp \
    forms/dropdown/intervaldropdowntest.cpp \
    forms/qguiformtest.cpp \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../code/release/ -lQGUITools
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../code/debug/ -lQGUITools
else:unix: LIBS += -L$$OUT_PWD/../code/ -lQGUITools

INCLUDEPATH += $$PWD/../code
DEPENDPATH += $$PWD/../code
