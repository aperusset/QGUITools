#ifndef DECIMALDROPDOWNTEST_H
#define DECIMALDROPDOWNTEST_H

#include <QtTest/QtTest>
#include "forms/dropdown/decimaldropdown.h"

class DecimalDropDownTest : public QObject {

    Q_OBJECT

    static constexpr double DEFAULT_MIN = 0.0;
    static constexpr double DEFAULT_MAX = 10.0;
    static constexpr double DEFAULT_INCREMENT = 1.0;
    static constexpr double PRESET_VALUE = 5.0;
    static const unsigned int TWO_DIGITS = 2;

    DecimalDropDown *defaultDropDown = new DecimalDropDown("Decimal Drop Down",
        DEFAULT_MIN, DEFAULT_MAX, DEFAULT_INCREMENT, PRESET_VALUE, nullptr);
    DecimalDropDown *twoDigitsDropDown = new DecimalDropDown("Decimal Drop Down",
        DEFAULT_MIN, DEFAULT_MAX, DEFAULT_INCREMENT, PRESET_VALUE, TWO_DIGITS, nullptr);

private slots:
    void shouldFailIfDisplayPrecisionLessThan1();
    void shouldReturnDefaultDisplayPrecision();
    void shouldReturnDefinedDisplayPrecision();
    void shouldBuildDisplayValueWithDefaultPrecision();
    void shouldBuildDisplayValueWithDefinedPrecision();

    void cleanupTestCase() {
        delete this->defaultDropDown;
        delete this->twoDigitsDropDown;
    }
};

#endif // DECIMALDROPDOWNTEST_H
