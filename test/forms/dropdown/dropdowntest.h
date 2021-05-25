#ifndef DROPDOWNTEST_H
#define DROPDOWNTEST_H

#include <QtTest/QtTest>
#include "fixture/testdropdown.h"

class DropDownTest : public QObject {

    Q_OBJECT

    TestDropDown *testDropDown = nullptr;

private slots:
    void getWidgetShouldReturnAComboBox();
    void getDataShouldReturnCurrentData();
    void setDataShouldDoNothingIfDataIsInvalid();
    void setDataShouldDoNothingIfDataIsNotKnown();
    void setDataShouldUpdateSelectedDataEmitHasChangedSignalAndSetModifiedToFalse();
    void populateShouldNotResetSelectedDataIfAlwaysPresentAndKeepModifiedStatus();
    void populateShouldResetSelectedDataToFirstAndModifiedToTrueIfSelectedIsInvalid();
    void populateShouldSortDataBasedOnValue();
    void userChangeShouldSetModifiedToTrue();

    void initTestCase() {
        this->testDropDown = new TestDropDown("Drop Down");
    }

    void cleanup() {
        this->testDropDown->setRealData({});
    }

    void cleanupTestCase() {
        delete this->testDropDown;
    }
};

#endif // DROPDOWNTEST_H
