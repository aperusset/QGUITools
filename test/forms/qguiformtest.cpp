#include "qguiformtest.h"
#include <QFormLayout>
#include <QSignalSpy>

const QString QGUIFormTest::DEFAULT_LABEL_TEXT = "labelName";

void QGUIFormTest::getLabelShouldReturnLabelWithDefaultTextAndSuffix() {

    // When
    auto *const label = this->testForm->getLabel();

    // Then
    QCOMPARE(label->text(), DEFAULT_LABEL_TEXT + QGUIForm::LABEL_TEXT_SUFFIX);
}

void QGUIFormTest::setLabelShouldSetTheLabelTextWithSuffix() {

    // Given
    const auto *const newLabel = "newLabelName";
    auto *const label = this->testForm->getLabel();

    // When
    this->testForm->setLabelText(newLabel);

    // Then
    QCOMPARE(label->text(), newLabel + QGUIForm::LABEL_TEXT_SUFFIX);
}

void QGUIFormTest::enableShouldEnableLabelAndWidget() {

    // When
    this->testForm->enable();

    // Then
    QVERIFY(this->testForm->getLabel()->isEnabled());
    QVERIFY(this->testForm->getWidget()->isEnabled());
    QVERIFY(this->testForm->isEnabled());
}

void QGUIFormTest::disableShouldDisableLabelAndWidget() {

    // When
    this->testForm->disable();

    // Then
    QVERIFY(!this->testForm->getLabel()->isEnabled());
    QVERIFY(!this->testForm->getWidget()->isEnabled());
    QVERIFY(!this->testForm->isEnabled());
}

void QGUIFormTest::setEnabledToTrueShouldEnable() {

    // When
    this->testForm->setEnabled(true);

    // Then
    QVERIFY(this->testForm->getLabel()->isEnabled());
    QVERIFY(this->testForm->getWidget()->isEnabled());
    QVERIFY(this->testForm->isEnabled());
}

void QGUIFormTest::setEnabledToFalseShouldDisable() {

    // When
    this->testForm->setEnabled(false);

    // Then
    QVERIFY(!this->testForm->getLabel()->isEnabled());
    QVERIFY(!this->testForm->getWidget()->isEnabled());
    QVERIFY(!this->testForm->isEnabled());
}

void QGUIFormTest::addToShouldAddLabelAndWidgetToFormLayout() {

    // Given
    QFormLayout layout;

    // When
    this->testForm->addTo(layout);

    // Then
    QCOMPARE(layout.rowCount(), 1);
    QCOMPARE(layout.count(), 2);
}

void QGUIFormTest::changedShouldEmitHasChangedWithValue() {

    // Given
    const auto *const emittedChange = "change";
    QSignalSpy spy(this->testForm, SIGNAL(hasChanged(const QString&)));

    // When
    this->testForm->changed(emittedChange);

    // Then
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.takeFirst().first(), emittedChange);

}

void QGUIFormTest::changedByUserShouldEmitUserHasChangedWithValue() {

    // Given
    const auto *const emittedChange = "change";
    QSignalSpy spy(this->testForm, SIGNAL(userHasChanged(const QString&)));

    // When
    this->testForm->changedByUser(emittedChange);

    // Then
    QCOMPARE(spy.count(), 1);
    QCOMPARE(spy.takeFirst().first(), emittedChange);
}
