#ifndef MAILVALIDATORTEST_H
#define MAILVALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/mailvalidator.h"

class MailValidatorTest : public QObject {

    Q_OBJECT

    const MailValidator &validator = MailValidator::mandatory();

private slots:
    void shouldBeValid();
    void shouldBeInvalid();
};

#endif // MAILVALIDATORTEST_H
