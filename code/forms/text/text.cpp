#include "text.h"

const QColor Text::VALID_COLOR(0, 0, 0);
const QColor Text::INVALID_COLOR(255, 0, 0);
const QString Text::DEFAULT_REGEXP = R"([\w\W\s\.]{3,})";

Text::Text(const QString &labelText, const bool mandatory, QWidget *parent) :
    Text(labelText, mandatory, "", DEFAULT_FIELD_WIDTH, nullptr, parent) {}

Text::Text(const QString &labelText, const bool mandatory, const unsigned int width, QWidget *parent) :
    Text(labelText, mandatory, "", width, nullptr, parent) {}

Text::Text(const QString &labelText, const bool mandatory, const unsigned int width, QRegExp *validator, QWidget *parent) :
    Text(labelText, mandatory, "", width, validator, parent) {}

Text::Text(const QString &labelText, const bool mandatory, const QString &defaultValue, QWidget *parent) :
    Text(labelText, mandatory, defaultValue, DEFAULT_FIELD_WIDTH, nullptr, parent) {}

Text::Text(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QWidget *parent) :
    Text(labelText, mandatory, defaultValue, width, nullptr, parent) {}

Text::Text(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QRegExp *validator, QWidget *parent) :
    QGUIForm(labelText, parent), mandatory(mandatory), lineEdit(new QLineEdit(defaultValue, this)),
    validator(validator == nullptr ? new QRegExp(DEFAULT_REGEXP) : validator) {
    this->lineEdit->setMinimumWidth((int)width);
    this->lineEdit->setMaximumWidth((int)width);
    connect(this->lineEdit, SIGNAL(textChanged(QString&)), this, SLOT(hasChanged(QString&)));
    connect(this->lineEdit, SIGNAL(textEdited(QString&)), this, SLOT(userHasChanged(QString&)));
}
const QString DEFAULT_REGEXP;
Text::~Text() {
    delete this->lineEdit;
    delete this->validator;
}

auto Text::isMandatory() const -> bool {
    return this->mandatory;
}

void Text::setMandatory(const bool mandatory) {
    this->mandatory = mandatory;
}

auto Text::isValid() const -> bool {
    auto const trimmedText = this->getValue();
    auto const valid = (
        (this->mandatory && trimmedText.isEmpty()) ||
        this->validator->exactMatch(trimmedText)
    );
    auto palette = this->getLabel()->palette();
    palette.setColor(QPalette::WindowText, valid ? VALID_COLOR : INVALID_COLOR);
    this->getLabel()->setPalette(palette);
    return valid;
}

auto Text::getValue() const -> QString {
    return this->lineEdit->text().trimmed();
}

void Text::setValue(const QString &value) {
    this->lineEdit->setText(value.trimmed());
}

auto Text::isReadOnly() const -> bool {
    return this->lineEdit->isReadOnly();
}

void Text::setReadOnly(const bool readOnly) {
    this->lineEdit->setReadOnly(readOnly);
}

auto Text::getWidget() const -> QWidget* {
    return this->lineEdit;
}
