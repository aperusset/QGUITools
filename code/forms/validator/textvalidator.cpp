#include "forms/validator/textvalidator.h"
#include <string>

TextValidator::TextValidator(const bool mandatory) :
    Validator(mandatory, R"(.+)") {}

TextValidator::TextValidator(const bool mandatory, const unsigned int minLength,
                             const unsigned int maxLength) :
    Validator(mandatory, QString(R"(.{%1,%2})").arg(minLength).arg(maxLength)) {
    if (minLength > maxLength) {
        throw std::string("Max length must be greater or equals to min.");
    }
}
