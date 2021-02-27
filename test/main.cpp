#include <QApplication>
#include <list>
#include <memory>
#include <QObject>
#include <QTest>
#include "qguicontainertest.h"
#include "forms/qguiformtest.h"
#include "forms/dropdown/dropdowntest.h"
#include "forms/dropdown/intervaldropdowntest.h"

auto main(int argc, char *argv[]) -> int {

    QApplication application(argc, argv);

    auto tests = std::list<std::shared_ptr<QObject>>{
        std::make_shared<QGUIContainerTest>(),
        std::make_shared<QGUIFormTest>(),
        std::make_shared<DropDownTest>(),
        std::make_shared<IntervalDropDownTest>()
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
