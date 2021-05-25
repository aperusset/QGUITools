#include "textvalidatortest.h"

void TextValidatorTest::shouldFailIfMinGreaterThanMax() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        TextValidator(true, 10U, 0U),
        std::string
    );
}

void TextValidatorTest::shouldHaveUnconstrainedRegularExpression() {

    // Given
    auto const &textValidator = TextValidator(true);

    // When
    auto const regularExpression = textValidator.getRegularExpression();

    // Then
    QCOMPARE(
        regularExpression.pattern(),
        QRegularExpression::anchoredPattern(R"(.+)")
    );
}

void TextValidatorTest::shouldHaveMinMaxRegularExpression() {

    // Given
    auto const &textValidator = TextValidator(true, MIN_LENGTH, MAX_LENGTH);

    // When
    auto const regularExpression = textValidator.getRegularExpression();

    // Then
    QCOMPARE(
        regularExpression.pattern(),
        QRegularExpression::anchoredPattern(
            ".{" + QString::number(MIN_LENGTH) + "," +
            QString::number(MAX_LENGTH) + QString("}")
        )
    );
}

void TextValidatorTest::shouldValidateAllText() {

    // Given
    auto const &textValidator = TextValidator(true);

    // When / Then
    QVERIFY(textValidator.isValid("a"));
    QVERIFY(textValidator.isValid("aaaa"));
}

void TextValidatorTest::shouldInvalidateTextIfShorterThanMin() {

    // Given
    auto const &textValidator = TextValidator(true, 2, 2);

    // When / Then
    QVERIFY(!textValidator.isValid("a"));
    QVERIFY(textValidator.isValid("aa"));
}

void TextValidatorTest::shouldInvalidateTextIfGreaterThanMax() {

    // Given
    auto const &textValidator = TextValidator(true, 2, 2);

    // When / Then
    QVERIFY(textValidator.isValid("aa"));
    QVERIFY(!textValidator.isValid("aaa"));
}
