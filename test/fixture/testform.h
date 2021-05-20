#ifndef TESTFORM_H
#define TESTFORM_H

#include "forms/qguiform.h"

class TestForm : public QGUIForm {

    QWidget * const widget;
    bool valid = true;

public:
    explicit TestForm(const QString &labelText) : QGUIForm(labelText, nullptr), widget(new QWidget(this)) {}

    ~TestForm() {
        delete this->widget;
    }

    auto isValid() const -> bool override {
        return valid;
    }

    void setValid(bool valid) {
        this->valid = valid;
    }

    auto getWidget() const -> QWidget* override {
        return this->widget;
    }
};

#endif // TESTFORM_H
