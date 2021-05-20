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
        QApplication::setActiveWindow(this->testForm);
    }

    void getLabelShouldReturnLabelWithDefaultTextAndSuffix();
    void setLabelTextShouldSetTrimmedTextWithSuffix();
    void setLabelTextShouldFailIfBlank();
    void enableShouldEnableLabelAndWidget();
    void disableShouldDisableLabelAndWidget();
    void setEnabledToTrueShouldEnable();
    void setEnabledToFalseShouldDisable();
    void isValidShouldReturnTrueByDefault();
    void validateShouldUseValidColorIfValid();
    void validateShouldUseInvalidColorIfInvalid();
    void focusShouldGiveFocusToWidget();
    void addToShouldAddLabelAndWidgetToFormLayout();

    void cleanup() {
        delete this->testForm;
    }
};

#endif // QGUIFORMTEST_H
