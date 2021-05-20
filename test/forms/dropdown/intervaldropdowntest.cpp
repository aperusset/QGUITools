#include "intervaldropdowntest.h"

void IntervalDropDownTest::shouldFailIfMinGreaterThanMax() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        new IntegerDropDown("", DEFAULT_MAX, DEFAULT_MIN, DEFAULT_INCREMENT, PRESET_VALUE, nullptr),
        std::string
    );
}

void IntervalDropDownTest::shouldFailtIfIntervalDoesNotIncrease() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        new IntegerDropDown("", DEFAULT_MIN, DEFAULT_MAX, 0U, PRESET_VALUE, nullptr),
        std::string
    );
}

void IntervalDropDownTest::shouldGenerateValuesRegardingParameters() {

    // When
    auto const data = this->dropDown->data();

    // Then
    QCOMPARE(data.size(), (DEFAULT_MAX - DEFAULT_MIN) / DEFAULT_INCREMENT + 1);
}

void IntervalDropDownTest::shouldBuildValue() {

    // Given
    auto const value = PRESET_VALUE;

    // When
    auto const builtValue = this->dropDown->buildValue(value);

    // Then
    QCOMPARE(builtValue.value<typename std::decay<decltype(value)>::type>(), value);
}
