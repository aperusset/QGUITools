#ifndef INTEGERDROPDOWNTEST_H
#define INTEGERDROPDOWNTEST_H

#include <QtTest/QtTest>
#include "forms/dropdown/integerdropdown.h"

class IntegerDropDownTest : public QObject {

    Q_OBJECT

    static const unsigned int DEFAULT_MIN = 0U;
    static const unsigned int DEFAULT_MAX = 10U;
    static const unsigned int DEFAULT_INCREMENT = 1U;
    static const unsigned int PRESET_VALUE = 5U;

    IntegerDropDown *dropDown = new IntegerDropDown("Integer Drop Down",
        DEFAULT_MIN, DEFAULT_MAX, DEFAULT_INCREMENT, PRESET_VALUE, nullptr);

private slots:
    void shouldBuildDisplayValue();

    void cleanupTestCase() {
        delete this->dropDown;
    }
};

#endif // INTEGERDROPDOWNTEST_H
