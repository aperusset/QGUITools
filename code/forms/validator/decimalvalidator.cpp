#include "forms/validator/decimalvalidator.h"

const QString DecimalValidator::REGULAR_EXPRESSION = R"([-\+]?\d*(\.\d*)?)";

DecimalValidator::DecimalValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESSION) {}

auto DecimalValidator::mandatory() -> const DecimalValidator& {
    static DecimalValidator mandatoryDecimalValidator(true);
    return mandatoryDecimalValidator;
}

auto DecimalValidator::notMandatory() -> const DecimalValidator& {
    static DecimalValidator notMandatoryDecimalValidator(false);
    return notMandatoryDecimalValidator;
}
