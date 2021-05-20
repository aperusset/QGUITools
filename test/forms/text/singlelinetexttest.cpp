#include "singlelinetexttest.h"
#include <QSignalSpy>

void SingleLineTextTest::shouldFailWithNullValidator() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        SingleLineText("label", nullptr, nullptr),
        std::string
    );
}

void SingleLineTextTest::shouldSetValidatorAndWidthToDefault() {

    // Given
    auto const expectedMandatory = true;
    const SingleLineText singleLineText("label", expectedMandatory, nullptr);

    // When
    auto const &lineEdit = singleLineText.getLineEdit();
    auto const &validator = singleLineText.getValidator();

    // Then
    QCOMPARE(lineEdit.minimumWidth(), SingleLineText::DEFAULT_FIELD_WIDTH);
    QCOMPARE(lineEdit.maximumWidth(), SingleLineText::DEFAULT_FIELD_WIDTH);
    QCOMPARE(validator.isMandatory(), expectedMandatory);
    QCOMPARE(
        validator.getRegularExpression().pattern(),
        QRegularExpression::anchoredPattern(SingleLineText::DEFAULT_REGULAR_EXPRESSION)
    );
}

void SingleLineTextTest::getWidgetShouldReturnLineEdit() {

    // Given
    auto *const widget = this->testSingleLineText->getWidget();

    // When
    auto *const lineEdit = dynamic_cast<QLineEdit*>(widget);

    // Then
    QVERIFY(lineEdit != nullptr);
}

void SingleLineTextTest::getTextShouldReturnTrimmedText() {

    // Given
    const QString value = " value  ";

    // When
    this->testSingleLineText->setText(value);
    auto const textValue = this->testSingleLineText->getText();

    // Then
    QCOMPARE(textValue, value.trimmed());
}

void SingleLineTextTest::setTextShouldTrimEmitAndValidate() {

    // Given
    const QString value = " value  ";
    QSignalSpy spyHasChanged(this->testSingleLineText, SIGNAL(hasChanged()));
    QSignalSpy spyUserHasChanged(this->testSingleLineText, SIGNAL(userHasChanged()));

    // When
    this->testSingleLineText->setText("v");
    this->testSingleLineText->setText(value);
    auto const color = this->testSingleLineText->getLabel().palette().color(QPalette::WindowText);

    // Then
    QCOMPARE(spyHasChanged.count(), 2);
    QCOMPARE(spyUserHasChanged.count(), 0);
    QCOMPARE(this->testSingleLineText->getText(), value.trimmed());
    QCOMPARE(color, Validator::VALID_COLOR);
}

void SingleLineTextTest::setTextShouldDoNothingWhenNoChange() {

    // Given
    const QString value = "value";
    QSignalSpy spyHasChanged(this->testSingleLineText, SIGNAL(hasChanged()));
    QSignalSpy spyUserHasChanged(this->testSingleLineText, SIGNAL(userHasChanged()));

    // When
    this->testSingleLineText->setText(value);
    this->testSingleLineText->setText(value);

    // Then
    QCOMPARE(spyHasChanged.count(), 1);
    QCOMPARE(spyUserHasChanged.count(), 0);
}

void SingleLineTextTest::isReadOnlyShouldReturnTrue() {

    // Given / When
    this->testSingleLineText->setReadOnly(false);
    this->testSingleLineText->setReadOnly(true);

    // Then
    QVERIFY(this->testSingleLineText->isReadOnly());
}

void SingleLineTextTest::isReadOnlyShouldReturnFalse() {

    // Given / When
    this->testSingleLineText->setReadOnly(true);
    this->testSingleLineText->setReadOnly(false);

    // Then
    QVERIFY(!this->testSingleLineText->isReadOnly());
}

void SingleLineTextTest::setWidthShouldUpdateMinMaxWidth() {

    // Given
    auto const expectedWidth = 42;
    auto const &lineEdit = this->testSingleLineText->getLineEdit();

    // When
    this->testSingleLineText->setWidth(expectedWidth);

    // Then
    QCOMPARE(lineEdit.minimumWidth(), expectedWidth);
    QCOMPARE(lineEdit.maximumWidth(), expectedWidth);
}

void SingleLineTextTest::setEchoModeShouldUpdateEchoMode() {

    // Given
    auto const expectedEchoMode = QLineEdit::Password;
    auto const &lineEdit = this->testSingleLineText->getLineEdit();

    // When
    this->testSingleLineText->setEchoMode(expectedEchoMode);

    // Then
    QCOMPARE(lineEdit.echoMode(), expectedEchoMode);
}

void SingleLineTextTest::isValidShouldReturnTrue() {

    // Given / When
    this->testSingleLineText->setText("value");

    // Then
    QVERIFY(this->testSingleLineText->isValid());
}

void SingleLineTextTest::isValidShouldReturnFalse() {

    // Given / When
    this->testSingleLineText->setText("");

    // Then
    QVERIFY(!this->testSingleLineText->isValid());
}

void SingleLineTextTest::userEditShouldEmitAndValidate() {

    // Given
    const QString expectedText = "a";
    QSignalSpy spyHasChanged(this->testSingleLineText, SIGNAL(hasChanged()));
    QSignalSpy spyUserHasChanged(this->testSingleLineText, SIGNAL(userHasChanged()));

    // When
    QTest::keyClicks(this->testSingleLineText->getWidget(), expectedText);
    QTest::keyClicks(this->testSingleLineText->getWidget(), expectedText);
    auto const color = this->testSingleLineText->getLabel().palette().color(QPalette::WindowText);

    // Then
    QCOMPARE(this->testSingleLineText->getText(), expectedText + expectedText);
    QCOMPARE(spyHasChanged.count(), 0);
    QCOMPARE(spyUserHasChanged.count(), 2);
    QCOMPARE(color, Validator::VALID_COLOR);
}

void SingleLineTextTest::userInvalidEditShouldEmitAndInvalidate() {

    // Given
    QSignalSpy spyHasChanged(this->testSingleLineText, SIGNAL(hasChanged()));
    QSignalSpy spyUserHasChanged(this->testSingleLineText, SIGNAL(userHasChanged()));

    // When
    QTest::keyClicks(this->testSingleLineText->getWidget(), "v");
    auto const color = this->testSingleLineText->getLabel().palette().color(QPalette::WindowText);

    // Then
    QCOMPARE(spyHasChanged.count(), 0);
    QCOMPARE(spyUserHasChanged.count(), 1);
    QCOMPARE(color, Validator::INVALID_COLOR);
}
