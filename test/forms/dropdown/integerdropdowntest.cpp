#include "integerdropdowntest.h"

void IntegerDropDownTest::shouldBuildDisplayValue() {

    // Given
    auto const value = PRESET_VALUE;

    // When
    auto const builtDisplayValue = this->dropDown->buildDisplayValue(value);

    // Then
    QCOMPARE(builtDisplayValue, QString::number(value));
}
