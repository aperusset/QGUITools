#include <QApplication>
#include <list>
#include <memory>
#include <QObject>
#include <QTest>
#include "qguicontainertest.h"
#include "forms/qguiformtest.h"
#include "forms/dropdown/dropdowntest.h"
#include "forms/dropdown/intervaldropdowntest.h"
#include "forms/dropdown/integerdropdowntest.h"
#include "forms/dropdown/decimaldropdowntest.h"
#include "forms/validator/validatortest.h"
#include "forms/validator/decimalvalidatortest.h"
#include "forms/validator/integervalidatortest.h"
#include "forms/validator/mailvalidatortest.h"
#include "forms/validator/phonevalidatortest.h"
#include "forms/validator/textvalidatortest.h"
#include "forms/text/singlelinetexttest.h"

auto main(int argc, char *argv[]) -> int {

    QApplication application(argc, argv);

    auto tests = std::list<std::shared_ptr<QObject>>{
        std::make_shared<QGUIContainerTest>(),
        std::make_shared<QGUIFormTest>(),
        std::make_shared<DropDownTest>(),
        std::make_shared<IntervalDropDownTest>(),
        std::make_shared<IntegerDropDownTest>(),
        std::make_shared<DecimalDropDownTest>(),
        std::make_shared<ValidatorTest>(),
        std::make_shared<DecimalValidatorTest>(),
        std::make_shared<IntegerValidatorTest>(),
        std::make_shared<MailValidatorTest>(),
        std::make_shared<PhoneValidatorTest>(),
        std::make_shared<TextValidatorTest>(),
        std::make_shared<SingleLineTextTest>()
    };

    try {

        for (auto &test : tests) {
            if (QTest::qExec(test.get(), argc, argv)) {
                return EXIT_FAILURE;
            }
        }
    } catch (std::string &exception) {
        qFatal("Uncaught exception : %s", exception.c_str());
        return EXIT_FAILURE;
    } catch (std::bad_function_call &exception) {
        qFatal("Uncaught exception : %s", exception.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
