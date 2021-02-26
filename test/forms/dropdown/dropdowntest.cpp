#include "dropdowntest.h"
#include <QSignalSpy>

void DropDownTest::getWidgetShouldReturnAComboBox() {

    // Given
    auto *const widget = this->testDropDown->getWidget();

    // When
    auto *const comboBox = dynamic_cast<QComboBox*>(widget);

    // Then
    QVERIFY(comboBox != nullptr);
}

void DropDownTest::getDataShouldReturnCurrentData() {

    // Given
    auto const selectedValue = 1;
    this->testDropDown->setRealData({{selectedValue, "test"}});
    this->testDropDown->setData(selectedValue);

    // When
    auto const data = this->testDropDown->getData<int>();

    // Then
    QCOMPARE(data, selectedValue);
}

void DropDownTest::setDataShouldDoNothingIfDataIsInvalid() {

    // Given
    auto const selectedValue = 2;
    this->testDropDown->setRealData({{1, "test"}, {selectedValue, "test2"}});
    this->testDropDown->setData(selectedValue);

    // When
    this->testDropDown->setData(QVariant::Invalid);

    // Then
    QCOMPARE(this->testDropDown->getData<int>(), selectedValue);
}

void DropDownTest::setDataShouldDoNothingIfDataIsNotKnown() {

    // Given
    auto const selectedValue = 2;
    this->testDropDown->setRealData({{1, "test"}, {selectedValue, "test2"}});
    this->testDropDown->setData(selectedValue);

    // When
    this->testDropDown->setData(0);

    // Then
    QCOMPARE(this->testDropDown->getData<int>(), selectedValue);
}

void DropDownTest::setDataShouldUpdateSelectedDataAndEmitHasChangedSignal() {

    // Given
    auto const selectedValue = 2;
    this->testDropDown->setRealData({{1, "test"}, {selectedValue, "test2"}});
    QSignalSpy spyHasChanged(this->testDropDown, SIGNAL(hasChanged()));
    QSignalSpy spyUserHasChanged(this->testDropDown, SIGNAL(userHasChanged()));

    // When
    this->testDropDown->setData(selectedValue);

    // Then
    QCOMPARE(this->testDropDown->getData<int>(), selectedValue);
    QCOMPARE(spyHasChanged.count(), 1);
    QCOMPARE(spyUserHasChanged.count(), 0);
}

void DropDownTest::populateShouldNotResetSelectedDataIfAlwaysPresent() {

    // Given
    auto const selectedValue = 2;
    this->testDropDown->setRealData({{1, "test"}, {selectedValue, "test2"}});
    this->testDropDown->setData(selectedValue);

    // When
    this->testDropDown->setRealData({{selectedValue, "test2"}});

    // Then
    QCOMPARE(this->testDropDown->getData<int>(), selectedValue);
}

void DropDownTest::populateShouldResetSelectedDataToFirstIfSelectedIsInvalid() {

    // Given
    auto const firstValue = 1;
    auto const selectedValue = 2;
    this->testDropDown->setRealData({{firstValue, "test"}, {selectedValue, "test2"}});
    this->testDropDown->setData(selectedValue);

    // When
    this->testDropDown->setRealData({{firstValue, "test"}});

    // Then
    QCOMPARE(this->testDropDown->getData<int>(), firstValue);
}

void DropDownTest::populateShouldSortDataBasedOnValue() {

    // Given
    auto const firstElement = 0;
    auto const secondElement = 1;
    this->testDropDown->setRealData({{secondElement, "zzz"}, {firstElement, "aaa"}});

    // When
    auto *const comboBox = dynamic_cast<QComboBox*>(this->testDropDown->getWidget());

    // Then
    QCOMPARE(comboBox->findData(firstElement), 0);
    QCOMPARE(comboBox->findData(secondElement), 1);
}
