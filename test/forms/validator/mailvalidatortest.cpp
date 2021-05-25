#include "mailvalidatortest.h"

void MailValidatorTest::shouldBeValid() {

    std::list<QString> validValues = {
        "mail@test.com",
        "mail.test@test.com",
        "mail-test@test.com",
        "mail@test.test.com",
        "mail@test-test.com"
    };

    for(const QString& validValue : validValues) {
        QVERIFY(validator.isValid(validValue));
    }
}

void MailValidatorTest::shouldBeInvalid() {

    std::list<QString> invalidValues = {
        "invalid",
        "@test.com"
        "mail@.com"
        "mail@"
    };

    for(const QString& invalidValue : invalidValues) {
        QVERIFY(!validator.isValid(invalidValue));
    }
}
