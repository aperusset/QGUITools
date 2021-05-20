#include "integervalidatortest.h"

void IntegerValidatorTest::shouldBeValid() {

    std::list<QString> validValues = {
        "", "-", "+", "-1", "-42", "+1", "+42", "1", "42"
    };

    for(const QString& validValue : validValues) {
        QVERIFY(validator.isValid(validValue));
    }
}

void IntegerValidatorTest::shouldBeInvalid() {

    std::list<QString> invalidValues = {
        "invalid", ",", "--1", "++1", "1..",
        "1.a", ".a", "-a", "+a"
    };

    for(const QString& validValue : invalidValues) {
        QVERIFY(!validator.isValid(validValue));
    }
}
