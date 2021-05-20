#include "qguiformtest.h"
#include <QFormLayout>
#include "forms/validator/validator.h"

const QString QGUIFormTest::DEFAULT_LABEL_TEXT = "labelName";

void QGUIFormTest::getLabelShouldReturnLabelWithDefaultTextAndSuffix() {

    // Given / When
    auto const &label = this->testForm->getLabel();

    // Then
    QCOMPARE(label.text(), DEFAULT_LABEL_TEXT + QGUIForm::LABEL_TEXT_SUFFIX);
}

void QGUIFormTest::setLabelTextShouldSetTrimmedTextWithSuffix() {

    // Given
    const QString newLabel = " newLabelName  ";
    auto const &label = this->testForm->getLabel();

    // When
    this->testForm->setLabelText(newLabel);

    // Then
    QCOMPARE(label.text(), newLabel.trimmed() + QGUIForm::LABEL_TEXT_SUFFIX);
}

void QGUIFormTest::setLabelTextShouldFailIfBlank() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        this->testForm->setLabelText(" "),
        std::string
    );
}

void QGUIFormTest::enableShouldEnableLabelAndWidget() {

    // Given / When
    this->testForm->enable();

    // Then
    QVERIFY(this->testForm->getLabel().isEnabled());
    QVERIFY(this->testForm->getWidget()->isEnabled());
    QVERIFY(this->testForm->isEnabled());
}

void QGUIFormTest::disableShouldDisableLabelAndWidget() {

    // Given / When
    this->testForm->disable();

    // Then
    QVERIFY(!this->testForm->getLabel().isEnabled());
    QVERIFY(!this->testForm->getWidget()->isEnabled());
    QVERIFY(!this->testForm->isEnabled());
}

void QGUIFormTest::setEnabledToTrueShouldEnable() {

    // Given / When
    this->testForm->setEnabled(true);

    // Then
    QVERIFY(this->testForm->getLabel().isEnabled());
    QVERIFY(this->testForm->getWidget()->isEnabled());
    QVERIFY(this->testForm->isEnabled());
}

void QGUIFormTest::setEnabledToFalseShouldDisable() {

    // Given / When
    this->testForm->setEnabled(false);

    // Then
    QVERIFY(!this->testForm->getLabel().isEnabled());
    QVERIFY(!this->testForm->getWidget()->isEnabled());
    QVERIFY(!this->testForm->isEnabled());
}

void QGUIFormTest::isValidShouldReturnTrueByDefault() {

    // Given / When / Then
    QVERIFY(this->testForm->isValid());
}

void QGUIFormTest::validateShouldUseValidColorIfValid() {

    // Given
    this->testForm->setValid(true);

    // When
    this->testForm->validate();
    auto const color = this->testForm->getLabel().palette().color(QPalette::WindowText);

    // Then
    QCOMPARE(color, Validator::VALID_COLOR);
}

void QGUIFormTest::validateShouldUseInvalidColorIfInvalid() {

    // Given
    this->testForm->setValid(false);

    // When
    this->testForm->validate();
    auto const color = this->testForm->getLabel().palette().color(QPalette::WindowText);

    // Then
    QCOMPARE(color, Validator::INVALID_COLOR);
}

void QGUIFormTest::focusShouldGiveFocusToWidget() {

    // When
    this->testForm->focus();

    // Then
    QVERIFY(this->testForm->getWidget()->hasFocus());
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
