#include "qguiform.h"

const QString LABEL_TEXT_SUFFIX = ":";

QGUIForm::QGUIForm(const QString &labelText, QWidget *parent) :
    QWidget(parent), label(new QLabel(this)){
    this->setLabelText(labelText);
}

QGUIForm::~QGUIForm() {
    delete this->label;
}

auto QGUIForm::getLabel() const -> QLabel* {
    return this->label;
}

void QGUIForm::setLabelText(const QString &labelText) {
    this->label->setText(labelText + LABEL_TEXT_SUFFIX);
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
    } else this->disable();
}

auto QGUIForm::isEnabled() const -> bool {
    return this->getWidget()->isEnabled();
}

void QGUIForm::focus() const {
    this->getWidget()->setFocus();
}

void QGUIForm::show() {
    this->label->show();
    this->getWidget()->show();
}

void QGUIForm::hide() {
    this->label->hide();
    this->getWidget()->hide();
}

void QGUIForm::changed(const QString &value) {
    emit hasChanged(value);
}

void QGUIForm::changedByUser(const QString &value) {
    emit userHasChanged(value);
}
