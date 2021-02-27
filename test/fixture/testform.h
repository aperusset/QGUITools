#ifndef TESTFORM_H
#define TESTFORM_H

#include "forms/qguiform.h"

class TestForm : public QGUIForm {

    QWidget * const widget;

public:
    explicit TestForm(const QString &labelText) : QGUIForm(labelText, nullptr), widget(new QWidget(this)) {}

    ~TestForm() {
        delete this->widget;
    }

    auto getWidget() const -> QWidget* override {
        return this->widget;
    }
};

#endif // TESTFORM_H
