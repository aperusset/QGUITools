#ifndef TEXTVALIDATOR_H
#define TEXTVALIDATOR_H

#include <limits>
#include "forms/validator/validator.h"

class TextValidator : public Validator {
 public:
    explicit TextValidator(const bool mandatory);
    TextValidator(const bool mandatory, const unsigned int minLength,
                  const unsigned int maxLength = UINT_MAX);
};

#endif  // TEXTVALIDATOR_H
