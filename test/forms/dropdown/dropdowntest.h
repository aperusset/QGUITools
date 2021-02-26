#ifndef DROPDOWNTEST_H
#define DROPDOWNTEST_H

#include <QtTest/QtTest>
#include "fixture/testdropdown.h"

class DropDownTest : public QObject {

    Q_OBJECT

    TestDropDown *testDropDown = new TestDropDown("Drop Down");

private slots:
    void getWidgetShouldReturnAComboBox();
    void getDataShouldReturnCurrentData();
    void setDataShouldDoNothingIfDataIsInvalid();
    void setDataShouldDoNothingIfDataIsNotKnown();
    void setDataShouldUpdateSelectedData();
    void populateShouldNotResetSelectedDataIfAlwaysPresent();
    void populateShouldResetSelectedDataToFirstIfSelectedIsInvalid();
    void populateShouldSortDataBasedOnValue();

    void cleanup() {
        this->testDropDown->setRealData({});
    }

    void cleanupTestCase() {
        delete this->testDropDown;
    }
};

#endif // DROPDOWNTEST_H
