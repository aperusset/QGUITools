#include "phonevalidatortest.h"

void PhoneValidatorTest::shouldBeValid() {

    std::list<QString> validValues = {
        "+00000",
        "+00000",
        "000000",
        "+000000000000000",
        "0000000000000000"
    };

    for(const QString& validValue : validValues) {
        QVERIFY(validator.isValid(validValue));
    }
}

void PhoneValidatorTest::shouldBeInvalid() {

    std::list<QString> invalidValues = {
        "-412548",
        "4125",
        "+0000",
        "+0000000000000000"
    };

    for(const QString& invalidValue : invalidValues) {
        QVERIFY(!validator.isValid(invalidValue));
    }
}
