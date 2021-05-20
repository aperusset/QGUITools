#include "decimaldropdowntest.h"

void DecimalDropDownTest::shouldFailIfDisplayPrecisionLessThan1() {

    // Given / When / Then
    QVERIFY_EXCEPTION_THROWN(
        new DecimalDropDown("", DEFAULT_MIN, DEFAULT_MAX, 0U, PRESET_VALUE, nullptr),
        std::string
    );
}

void DecimalDropDownTest::shouldReturnDefaultDisplayPrecision() {

    // When
    auto const displayPrecision = defaultDropDown->getDisplayPrecision();

    // Then
    QCOMPARE(displayPrecision, DecimalDropDown::DEFAULT_DISPLAY_PRECISON);
}

void DecimalDropDownTest::shouldReturnDefinedDisplayPrecision() {

    // When
    auto const displayPrecision = twoDigitsDropDown->getDisplayPrecision();

    // Then
    QCOMPARE(displayPrecision, TWO_DIGITS);
}

void DecimalDropDownTest::shouldBuildDisplayValueWithDefaultPrecision() {

    // When
    auto const builtDisplayValue = defaultDropDown->buildDisplayValue(PRESET_VALUE);

    // Then
    QCOMPARE(
        builtDisplayValue,
        QString::number(PRESET_VALUE, 'f', DecimalDropDown::DEFAULT_DISPLAY_PRECISON)
    );
}

void DecimalDropDownTest::shouldBuildDisplayValueWithDefinedPrecision() {

    // When
    auto const builtDisplayValue = twoDigitsDropDown->buildDisplayValue(PRESET_VALUE);

    // Then
    QCOMPARE(
        builtDisplayValue,
        QString::number(PRESET_VALUE, 'f', TWO_DIGITS)
    );
}
