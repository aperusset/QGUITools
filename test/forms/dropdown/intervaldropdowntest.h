#ifndef INTERVALDROPDOWNTEST_H
#define INTERVALDROPDOWNTEST_H

#include <QtTest/QtTest>
#include "forms/dropdown/intervaldropdown.h"
#include "forms/dropdown/integerdropdown.h"

class IntervalDropDownTest : public QObject {

    Q_OBJECT

    static const unsigned int DEFAULT_MIN = 0U;
    static const unsigned int DEFAULT_MAX = 10U;
    static const unsigned int DEFAULT_INCREMENT = 1U;
    static const unsigned int PRESET_VALUE = 5U;

    IntegerDropDown *dropDown = new IntegerDropDown("Interval Drop Down",
        DEFAULT_MIN, DEFAULT_MAX, DEFAULT_INCREMENT, PRESET_VALUE, nullptr);

private slots:
    static void shouldFailIfMinGreaterThanMax();
    static void shouldFailtIfMinDoesNotIncrease();
    void shouldGenerateValuesRegardingParameters();
    void shouldBuildValue();

    void cleanupTestCase() {
        delete this->dropDown;
    }
};

#endif // INTERVALDROPDOWNTEST_H
