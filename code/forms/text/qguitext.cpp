#include "qguitext.h"

const QColor QGUIText::VALID_COLOR(0, 0, 0);
const QColor QGUIText::INVALID_COLOR(255, 0, 0);
const QString QGUIText::DEFAULT_REGEXP = R"([\w\W\s\.]{3,})";

QGUIText::QGUIText(const QString &labelText, const bool mandatory, QWidget *parent) :
    QGUIText(labelText, mandatory, "", DEFAULT_FIELD_WIDTH, nullptr, parent) {}

QGUIText::QGUIText(const QString &labelText, const bool mandatory, const unsigned int width, QWidget *parent) :
    QGUIText(labelText, mandatory, "", width, nullptr, parent) {}

QGUIText::QGUIText(const QString &labelText, const bool mandatory, const unsigned int width, QRegExp *validator, QWidget *parent) :
    QGUIText(labelText, mandatory, "", width, validator, parent) {}

QGUIText::QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, QWidget *parent) :
    QGUIText(labelText, mandatory, defaultValue, DEFAULT_FIELD_WIDTH, nullptr, parent) {}

QGUIText::QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QWidget *parent) :
    QGUIText(labelText, mandatory, defaultValue, width, nullptr, parent) {}

QGUIText::QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QRegExp *validator, QWidget *parent) :
    QGUIForm(labelText, parent), mandatory(mandatory), lineEdit(new QLineEdit(defaultValue, this)),
    validator(validator == nullptr ? new QRegExp(DEFAULT_REGEXP) : validator) {
    this->lineEdit->setMinimumWidth((int)width);
    this->lineEdit->setMaximumWidth((int)width);
    connect(this->lineEdit, SIGNAL(textChanged(QString&)), this, SLOT(hasChanged(QString&)));
    connect(this->lineEdit, SIGNAL(textEdited(QString&)), this, SLOT(userHasChanged(QString&)));
}
const QString DEFAULT_REGEXP;
QGUIText::~QGUIText() {
    delete this->lineEdit;
    delete this->validator;
}

auto QGUIText::isMandatory() const -> bool {
    return this->mandatory;
}

void QGUIText::setMandatory(const bool mandatory) {
    this->mandatory = mandatory;
}

auto QGUIText::isValid() const -> bool {
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

auto QGUIText::getValue() const -> QString {
    return this->lineEdit->text().trimmed();
}

void QGUIText::setValue(const QString &value) {
    this->lineEdit->setText(value.trimmed());
}

auto QGUIText::isReadOnly() const -> bool {
    return this->lineEdit->isReadOnly();
}

void QGUIText::setReadOnly(const bool readOnly) {
    this->lineEdit->setReadOnly(readOnly);
}

auto QGUIText::getWidget() const -> QWidget* {
    return this->lineEdit;
}
