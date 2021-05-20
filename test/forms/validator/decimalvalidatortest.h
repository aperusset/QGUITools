#ifndef DECIMALVALIDATORTEST_H
#define DECIMALVALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/decimalvalidator.h"

class DecimalValidatorTest : public QObject {

    Q_OBJECT

    const DecimalValidator &validator = DecimalValidator::mandatory();

private slots:
    void shouldBeValid();
    void shouldBeInvalid();
};

#endif // DECIMALVALIDATORTEST_H
