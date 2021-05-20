#ifndef SINGLELINETEXTTEST_H
#define SINGLELINETEXTTEST_H

#include <QtTest/QtTest>
#include "forms/text/singlelinetext.h"

class SingleLineTextTest : public QObject {

    Q_OBJECT

    SingleLineText *testSingleLineText = new SingleLineText("label", new Validator(true, R"(.{2,})"), nullptr);

private slots:
    void shouldFailWithNullValidator();
    void shouldSetValidatorAndWidthToDefault();
    void getWidgetShouldReturnLineEdit();
    void getTextShouldReturnTrimmedText();
    void setTextShouldTrimEmitAndValidate();
    void setTextShouldDoNothingWhenNoChange();
    void isReadOnlyShouldReturnTrue();
    void isReadOnlyShouldReturnFalse();
    void setWidthShouldUpdateMinMaxWidth();
    void setEchoModeShouldUpdateEchoMode();
    void isValidShouldReturnTrue();
    void isValidShouldReturnFalse();
    void userEditShouldEmitAndValidate();
    void userInvalidEditShouldEmitAndInvalidate();

    void cleanup() {
        this->testSingleLineText->setText("");
    }

    void cleanupTestCase() {
        delete this->testSingleLineText;
    }
};

#endif // SINGLELINETEXTTEST_H
