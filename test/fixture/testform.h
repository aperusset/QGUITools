#ifndef TESTFORM_H
#define TESTFORM_H

#include "forms/qguiform.h"

class TestForm : public QGUIForm {

    QWidget * const widget;

public:
    TestForm(const QString &labelText) : QGUIForm(labelText, nullptr), widget(new QWidget()) {}

    ~TestForm() {
        delete this->widget;
    }

    auto getWidget() const -> QWidget* {
        return this->widget;
    }
};

#endif // TESTFORM_H
