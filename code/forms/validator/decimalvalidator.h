#ifndef DECIMALVALIDATOR_H
#define DECIMALVALIDATOR_H

#include "forms/validator/validator.h"

// TODO wrap QDoubleValidator class ?
// https://doc.qt.io/qt-5/qdoublevalidator.html

class DecimalValidator : public Validator {
    explicit DecimalValidator(const bool mandatory);

 public:
    static const QString REGULAR_EXPRESSION;
    static const DecimalValidator& mandatory();
    static const DecimalValidator& notMandatory();
};

#endif  // DECIMALVALIDATOR_H
