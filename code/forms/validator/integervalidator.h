#ifndef INTEGERVALIDATOR_H
#define INTEGERVALIDATOR_H

#include "forms/validator/validator.h"

// TODO wrap QIntValidator class ?
// https://doc.qt.io/qt-5/qintvalidator.html

class IntegerValidator : public Validator {
    explicit IntegerValidator(const bool mandatory);

 public:
    static const QString REGULAR_EXPRESSION;
    static auto mandatory() -> const IntegerValidator&;
    static auto notMandatory() -> const IntegerValidator&;
};

#endif  // INTEGERVALIDATOR_H
