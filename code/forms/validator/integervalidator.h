#ifndef INTEGERVALIDATOR_H
#define INTEGERVALIDATOR_H

#include "forms/validator/validator.h"

// TODO wrap QIntValidator class ?
// https://doc.qt.io/qt-5/qintvalidator.html

class IntegerValidator : public Validator {
    explicit IntegerValidator(const bool mandatory);

 public:
    static const QString REGULAR_EXPRESSION;
    static const IntegerValidator& mandatory();
    static const IntegerValidator& notMandatory();
};

#endif  // INTEGERVALIDATOR_H
