#ifndef TEXTVALIDATORTEST_H
#define TEXTVALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/textvalidator.h"

class TextValidatorTest : public QObject {
    Q_OBJECT

    static const unsigned int MIN_LENGTH = 2;
    static const unsigned int MAX_LENGTH = 10;

 private slots:
    static void shouldFailIfMinGreaterThanMax();
    static void shouldHaveUnconstrainedRegularExpression();
    static void shouldHaveMinMaxRegularExpression();
    static void shouldValidateAllText();
    static void shouldInvalidateTextIfShorterThanMin();
    static void shouldInvalidateTextIfGreaterThanMax();
};

#endif // TEXTVALIDATORTEST_H
