#include "qguicontainertest.h"
#include <QSignalSpy>

const QString QGUIContainerTest::DEFAULT_CONTAINER_TITLE = "containerTitle";

void QGUIContainerTest::getIdShouldReturnDefinedId() {

    // When / Then
    QCOMPARE(this->testContainer->getId(), TestContainer::DEFAULT_ID);
}

void QGUIContainerTest::notifyShouldEmitHasChangedWithDefinedId() {

    // Given
    QSignalSpy spyHasChanged(this->testContainer, SIGNAL(hasChanged(const unsigned int)));

    // When
    this->testContainer->notify();
    auto const spied = spyHasChanged.first();

    // Then
    QCOMPARE(spyHasChanged.count(), 1);
    QCOMPARE(spied.first().toUInt(), TestContainer::DEFAULT_ID);
}

void QGUIContainerTest::waitShouldActiveWaitCursor() {

    // When
    this->testContainer->wait();

    // Then
    QCOMPARE(QApplication::overrideCursor()->shape(), Qt::CursorShape::WaitCursor);
}

void QGUIContainerTest::finishedShouldRestoreCursor() {

    // When
    this->testContainer->wait();
    this->testContainer->finished();

    // Then
    QCOMPARE(QApplication::overrideCursor(), nullptr);
}

void QGUIContainerTest::updateShouldCallUpdateButtons() {

    // When
    this->testContainer->update();

    // Then
    QVERIFY(this->testContainer->buttonsAreUpdated());
}
