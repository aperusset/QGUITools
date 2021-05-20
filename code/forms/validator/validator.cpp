#include "forms/validator/validator.h"
#include <utility>

const QColor Validator::VALID_COLOR = QColor(0, 0, 0);
const QColor Validator::INVALID_COLOR = QColor(255, 0, 0);

Validator::Validator(const bool mandatory, QString regularExpression) :
    mandatory(mandatory),
    regularExpression(new QRegularExpression(
        QRegularExpression::anchoredPattern(std::move(regularExpression)))) {}

Validator::~Validator() {
    delete this->regularExpression;
}

auto Validator::isMandatory() const -> bool {
    return this->mandatory;
}

auto Validator::getRegularExpression() const -> const QRegularExpression& {
    return *this->regularExpression;
}

auto Validator::isValid(const QString &value) const -> bool {
    return (!this->mandatory && value.isEmpty()) ||
            this->regularExpression->match(value).hasMatch();
}
