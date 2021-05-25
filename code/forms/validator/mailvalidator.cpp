#include "forms/validator/mailvalidator.h"

const QString MailValidator::REGULAR_EXPRESION =
    R"((?=.{1,64}@)[A-Za-z0-9_-]+(\.[A-Za-z0-9_-]+)*)"
    R"(@[^-][A-Za-z0-9-]+(\.[A-Za-z0-9-]+)*(\.[A-Za-z]{2,}))";

MailValidator::MailValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESION) {}

auto MailValidator::mandatory() -> const MailValidator& {
    static MailValidator mandatoryMailValidator(true);
    return mandatoryMailValidator;
}

auto MailValidator::notMandatory() -> const MailValidator& {
    static MailValidator notMandatoryMailValidator(false);
    return notMandatoryMailValidator;
}
