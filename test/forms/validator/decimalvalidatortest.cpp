#include "decimalvalidatortest.h"
#include <list>

void DecimalValidatorTest::shouldBeValid() {

    std::list<QString> validValues = {
        "", "-", "+", ".", "-.", "+.", "0.", ".0", "0", "0.0",
        "42", "1.", ".5", "111.222", "-.5", "+.678",
        "-1234.5678", "+4242.3", "-123.", "+987."
    };

    for(const QString& validValue : validValues) {
        QVERIFY(validator.isValid(validValue));
    }
}

void DecimalValidatorTest::shouldBeInvalid() {

    std::list<QString> invalidValues = {
        "invalid", ",", "--1", "++1", "1..",
        "1.a", ".a", "-a", "+a"
    };

    for(const QString& validValue : invalidValues) {
        QVERIFY(!validator.isValid(validValue));
    }
}
