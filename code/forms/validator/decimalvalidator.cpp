#include "forms/validator/decimalvalidator.h"

const QString DecimalValidator::REGULAR_EXPRESSION = R"([-\+]?\d*(\.\d*)?)";

DecimalValidator::DecimalValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESSION) {}

const DecimalValidator& DecimalValidator::mandatory() {
    static DecimalValidator mandatoryDecimalValidator(true);
    return mandatoryDecimalValidator;
}

const DecimalValidator& DecimalValidator::notMandatory() {
    static DecimalValidator notMandatoryDecimalValidator(false);
    return notMandatoryDecimalValidator;
}
