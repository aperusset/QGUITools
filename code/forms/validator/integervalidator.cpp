#include "forms/validator/integervalidator.h"

const QString IntegerValidator::REGULAR_EXPRESSION = R"([-\+]?\d*)";

IntegerValidator::IntegerValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESSION) {}

const IntegerValidator& IntegerValidator::mandatory() {
    static IntegerValidator mandatoryIntegerValidator(true);
    return mandatoryIntegerValidator;
}

const IntegerValidator& IntegerValidator::notMandatory() {
    static IntegerValidator notMandatoryIntegerValidator(false);
    return notMandatoryIntegerValidator;
}
