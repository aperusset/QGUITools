#ifndef VALIDATORTEST_H
#define VALIDATORTEST_H

#include <QtTest/QtTest>
#include "forms/validator/validator.h"

class ValidatorTest : public QObject {

    Q_OBJECT

    Validator *validator = new Validator(false, DEFAULT_REGEXP);
    Validator *mandatoryValidator = new Validator(true, DEFAULT_REGEXP);

    static const QString DEFAULT_REGEXP;

private slots:
    void shouldReturnMandatory();
    void shouldReturnNotMandatory();
    void shouldUseAnchoredPattern();
    void shouldBeValidIfNotMandatoryAndEmpty();
    void shouldBeValidIfNotMandatoryAndValid();
    void shouldBeInvalidIfNotMandatoryAndInvalid();
    void shouldBeInvalidIfMandatoryAndEmpty();
    void shouldBeInvalidIfMandatoryAndInvalid();
    void shouldBeValidIfMandatoryAndValid();

    void cleanupTestCase() {
        delete this->validator;
        delete this->mandatoryValidator;
    }
};

#endif // VALIDATORTEST_H
