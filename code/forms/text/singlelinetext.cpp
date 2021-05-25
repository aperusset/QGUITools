#include "forms/text/singlelinetext.h"
#include <QRegularExpressionValidator>
#include <string>
#include "forms/validator/textvalidator.h"

SingleLineText::SingleLineText(const QString &labelText, const bool mandatory,
                               QWidget *parent) :
    SingleLineText(labelText, new TextValidator(mandatory), parent) {}

SingleLineText::SingleLineText(const QString &labelText,
                               const Validator *validator, QWidget *parent) :
    QGUIForm(labelText, parent), lineEdit(new QLineEdit(this)),
    validator(validator) {
    if (validator == nullptr) {
        throw std::string("A validator must be provided.");
    }
    this->setWidth(DEFAULT_FIELD_WIDTH);
    this->lineEdit->setValidator(new QRegularExpressionValidator(
        this->validator->getRegularExpression(), this->lineEdit));
    connect(this->lineEdit, &QLineEdit::textEdited, this, [=] {
        emit userHasChanged();
        validate();
    });
}

SingleLineText::~SingleLineText() {
    delete this->lineEdit;
    delete this->validator;
}

auto SingleLineText::getLineEdit() const -> const QLineEdit& {
    return *this->lineEdit;
}

auto SingleLineText::getValidator() const -> const Validator& {
    return *this->validator;
}

auto SingleLineText::getText() const -> QString {
    return this->lineEdit->text().trimmed();
}

void SingleLineText::setText(const QString &text) {
    auto const trimmedText = text.trimmed();
    if (trimmedText != this->getText()) {
        this->lineEdit->setText(trimmedText);
        emit hasChanged();
        validate();
    }
}

auto SingleLineText::isReadOnly() const -> bool {
    return this->lineEdit->isReadOnly();
}

void SingleLineText::setReadOnly(const bool readOnly) {
    this->lineEdit->setReadOnly(readOnly);
}

void SingleLineText::setWidth(const int width) {
    this->lineEdit->setMinimumWidth(width);
    this->lineEdit->setMaximumWidth(width);
}

void SingleLineText::setEchoMode(const QLineEdit::EchoMode echoMode) {
    this->lineEdit->setEchoMode(echoMode);
}

auto SingleLineText::isModified() const -> bool {
    return this->lineEdit->isModified();
}

auto SingleLineText::isValid() const -> bool {
    return this->lineEdit->hasAcceptableInput() &&
           this->validator->isValid(this->getText());
}

auto SingleLineText::getWidget() const -> QWidget* {
    return this->lineEdit;
}
