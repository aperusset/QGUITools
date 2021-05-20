#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QWidget>
#include <QRegularExpression>
#include <QColor>

// TODO hold a QValidator / QRegularExpressionValidator object instead ?
// https://doc.qt.io/qt-5/qvalidator.html
// https://doc.qt.io/qt-5/qregularexpressionvalidator.html

class Validator {
    const bool mandatory;
    const QRegularExpression* const regularExpression;

 public:
    Validator(const bool mandatory, QString regularExpression);
    Validator(const Validator&) = delete;
    Validator(Validator&&) = delete;
    Validator& operator=(const Validator&) = delete;
    Validator& operator=(Validator&&) = delete;
    virtual ~Validator();

    auto isMandatory() const -> bool;
    auto getRegularExpression() const -> const QRegularExpression&;
    virtual auto isValid(const QString&) const -> bool;

    static const QColor VALID_COLOR;
    static const QColor INVALID_COLOR;
};

#endif  // VALIDATOR_H
