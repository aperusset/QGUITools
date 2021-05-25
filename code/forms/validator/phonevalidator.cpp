#include "forms/validator/phonevalidator.h"

const QString PhoneValidator::REGULAR_EXPRESSION = R"([+|0]?\d{5,15})";

PhoneValidator::PhoneValidator(const bool mandatory) :
    Validator(mandatory, REGULAR_EXPRESSION) {}

auto PhoneValidator::mandatory() -> const PhoneValidator& {
    static PhoneValidator mandatoryPhoneValidator(true);
    return mandatoryPhoneValidator;
}

auto PhoneValidator::notMandatory() -> const PhoneValidator& {
    static PhoneValidator notMandatoryPhoneValidator(false);
    return notMandatoryPhoneValidator;
}
