#ifndef MAILVALIDATOR_H
#define MAILVALIDATOR_H

#include "forms/validator/validator.h"

class MailValidator : public Validator {
    explicit MailValidator(const bool mandatory);

 public:
    static const QString REGULAR_EXPRESION;
    static auto mandatory() -> const MailValidator&;
    static auto notMandatory() -> const MailValidator&;
};

#endif  // MAILVALIDATOR_H
