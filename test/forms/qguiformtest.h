#ifndef QGUIFORMTEST_H
#define QGUIFORMTEST_H

#include <QtTest/QtTest>
#include "forms/qguiform.h"
#include "fixture/testform.h"

class QGUIFormTest : public QObject {

    Q_OBJECT

    TestForm *testForm = nullptr;

    static const QString DEFAULT_LABEL_TEXT;

private slots:
    void init() {
        this->testForm = new TestForm(DEFAULT_LABEL_TEXT);
    }

    void getLabelShouldReturnLabelWithDefaultTextAndSuffix();
    void setLabelShouldSetTheLabelTextWithSuffix();
    void enableShouldEnableLabelAndWidget();
    void disableShouldDisableLabelAndWidget();
    void setEnabledToTrueShouldEnable();
    void setEnabledToFalseShouldDisable();
    void addToShouldAddLabelAndWidgetToFormLayout();
    void changedShouldEmitHasChangedWithValue();
    void changedByUserShouldEmitUserHasChangedWithValue();

    // TODO how to test focus/show/hide as there is no visible QWidget ?

    void cleanup() {
        delete this->testForm;
    }
};

#endif // QGUIFORMTEST_H
