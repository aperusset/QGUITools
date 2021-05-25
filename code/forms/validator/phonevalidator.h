#ifndef PHONEVALIDATOR_H
#define PHONEVALIDATOR_H

#include "forms/validator/validator.h"

class PhoneValidator : public Validator {
    explicit PhoneValidator(const bool mandatory);

 public:
    static const QString REGULAR_EXPRESSION;
    static auto mandatory() -> const PhoneValidator&;
    static auto notMandatory() -> const PhoneValidator&;
};

#endif  // PHONEVALIDATOR_H
