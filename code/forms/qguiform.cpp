#include "forms/qguiform.h"
#include <string>
#include "forms/validator/validator.h"

const QString QGUIForm::LABEL_TEXT_SUFFIX = " : ";

QGUIForm::QGUIForm(const QString &labelText, QWidget *parent) :
    QWidget(parent), label(new QLabel(this)) {
    this->setLabelText(labelText);
}

QGUIForm::~QGUIForm() {
    delete this->label;
}

auto QGUIForm::getLabel() const -> const QLabel& {
    return *this->label;
}

void QGUIForm::setLabelText(const QString &labelText) {
    auto const trimmedLabelText = labelText.trimmed();
    if (trimmedLabelText.isEmpty()) {
        throw std::string("Label text cannot be empty.");
    }
    this->label->setText(trimmedLabelText + LABEL_TEXT_SUFFIX);
}

void QGUIForm::enable() {
    this->label->setEnabled(true);
    this->getWidget()->setEnabled(true);
}

void QGUIForm::disable() {
    this->label->setEnabled(false);
    this->getWidget()->setEnabled(false);
}

void QGUIForm::setEnabled(const bool enabled) {
    if (enabled) {
        this->enable();
    } else {
        this->disable();
    }
}

auto QGUIForm::isEnabled() const -> bool {
    return this->getWidget()->isEnabled();
}

auto QGUIForm::isModified() const -> bool {
    return false;
}

auto QGUIForm::isValid() const -> bool {
    return true;
}

void QGUIForm::validate() {
    auto palette = this->label->palette();
    palette.setColor(QPalette::WindowText,
        this->isValid() ? Validator::VALID_COLOR : Validator::INVALID_COLOR);
    this->label->setPalette(palette);
}

void QGUIForm::focus() const {
    this->getWidget()->setFocus();
}

void QGUIForm::addTo(QFormLayout &formLayout) {
    formLayout.addRow(this->label, this->getWidget());
}
