#ifndef PHONEVALIDATORTEST_H
#define PHONEVALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/phonevalidator.h"

class PhoneValidatorTest : public QObject {

    Q_OBJECT

    const PhoneValidator &validator = PhoneValidator::mandatory();

private slots:
    void shouldBeValid();
    void shouldBeInvalid();
};

#endif // PHONEVALIDATORTEST_H
