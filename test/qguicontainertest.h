#ifndef QGUICONTAINERTEST_H
#define QGUICONTAINERTEST_H

#include <QtTest/QtTest>
#include "fixture/testcontainer.h"

class QGUIContainerTest : public QObject {

    Q_OBJECT

    TestContainer *testContainer = nullptr;

    static const QString DEFAULT_CONTAINER_TITLE;

private slots:
    void init() {
        this->testContainer = new TestContainer(DEFAULT_CONTAINER_TITLE);
        QApplication::setActiveWindow(this->testContainer);
    }

    void getIdShouldReturnDefinedId();
    void notifyShouldEmitHasChangedWithDefinedId();
    void waitShouldActiveWaitCursor();
    void finishedShouldRestoreCursor();
    void updateShouldCallUpdateButtons();

    void cleanup() {
        QApplication::restoreOverrideCursor();
        delete this->testContainer;
    }
};

#endif // QGUICONTAINERTEST_H
