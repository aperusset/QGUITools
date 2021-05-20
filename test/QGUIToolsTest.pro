QMAKE_CXXFLAGS += -std=c++0x -std=gnu++11 -Wall
CONFIG += c++11

QT += testlib widgets
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    fixture/testcontainer.h \
    fixture/testdropdown.h \
    fixture/testform.h \
    forms/dropdown/decimaldropdowntest.h \
    forms/dropdown/dropdowntest.h \
    forms/dropdown/integerdropdowntest.h \
    forms/dropdown/intervaldropdowntest.h \
    forms/qguiformtest.h \
    forms/text/singlelinetexttest.h \
    forms/validator/decimalvalidatortest.h \
    forms/validator/integervalidatortest.h \
    forms/validator/validatortest.h \
    qguicontainertest.h

SOURCES += \
    forms/dropdown/decimaldropdowntest.cpp \
    forms/dropdown/dropdowntest.cpp \
    forms/dropdown/integerdropdowntest.cpp \
    forms/dropdown/intervaldropdowntest.cpp \
    forms/qguiformtest.cpp \
    forms/text/singlelinetexttest.cpp \
    forms/validator/decimalvalidatortest.cpp \
    forms/validator/integervalidatortest.cpp \
    forms/validator/validatortest.cpp \
    main.cpp \
    qguicontainertest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../code/release/ -lQGUITools
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../code/debug/ -lQGUITools
else:unix: LIBS += -L$$OUT_PWD/../code/ -lQGUITools

INCLUDEPATH += $$PWD/../code
DEPENDPATH += $$PWD/../code
