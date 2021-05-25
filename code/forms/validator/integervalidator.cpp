#include "forms/validator/integervalidator.h"

const QString IntegerValidator::REGULAR_EXPRESSION = R"([-\+]?\d*)";

IntegerValidator::IntegerValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESSION) {}

auto IntegerValidator::mandatory() -> const IntegerValidator& {
    static IntegerValidator mandatoryIntegerValidator(true);
    return mandatoryIntegerValidator;
}

auto IntegerValidator::notMandatory() -> const IntegerValidator& {
    static IntegerValidator notMandatoryIntegerValidator(false);
    return notMandatoryIntegerValidator;
}
