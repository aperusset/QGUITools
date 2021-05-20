#ifndef INTEGERVALIDATORTEST_H
#define INTEGERVALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/integervalidator.h"

class IntegerValidatorTest : public QObject {

    Q_OBJECT

    const IntegerValidator &validator = IntegerValidator::mandatory();

private slots:
    void shouldBeValid();
    void shouldBeInvalid();
};

#endif // INTEGERVALIDATORTEST_H
