#include "validatortest.h"

const QString ValidatorTest::DEFAULT_REGEXP = R"([\w\W\s\.]{3,})";

void ValidatorTest::shouldReturnMandatory() {

    // Given / When / Then
    QVERIFY(mandatoryValidator->isMandatory());
}

void ValidatorTest::shouldReturnNotMandatory() {

    // Given / When / Then
    QVERIFY(!validator->isMandatory());
}

void ValidatorTest::shouldUseAnchoredPattern() {

    // Given
    const QString expectedPattern = QRegularExpression::anchoredPattern(DEFAULT_REGEXP);

    // When
    auto const pattern = this->validator->getRegularExpression().pattern();

    // Then
    QCOMPARE(pattern, expectedPattern);
}

void ValidatorTest::shouldBeValidIfNotMandatoryAndEmpty() {

    // Given
    const QString validValue = "";

    // When / Then
    QVERIFY(validator->isValid(validValue));
}

void ValidatorTest::shouldBeValidIfNotMandatoryAndValid() {

    // Given
    const QString validValue = "valid";

    // When / Then
    QVERIFY(validator->isValid(validValue));
}

void ValidatorTest::shouldBeInvalidIfNotMandatoryAndInvalid() {

    // Given
    const QString invalidValue = "f";

    // When / Then
    QVERIFY(!validator->isValid(invalidValue));
}

void ValidatorTest::shouldBeInvalidIfMandatoryAndEmpty() {

    // Given
    const QString invalidValue = "";

    // When / Then
    QVERIFY(!mandatoryValidator->isValid(invalidValue));
}

void ValidatorTest::shouldBeInvalidIfMandatoryAndInvalid() {

    // Given
    const QString invalidValue = "f";

    // When / Then
    QVERIFY(!mandatoryValidator->isValid(invalidValue));
}

void ValidatorTest::shouldBeValidIfMandatoryAndValid() {

    // Given
    const QString validValue = "valid";

    // When / Then
    QVERIFY(mandatoryValidator->isValid(validValue));
}
