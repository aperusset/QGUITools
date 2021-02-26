#include <QApplication>
#include <list>
#include <memory>
#include <QObject>
#include <QTest>
#include "forms/qguiformtest.h"

auto main(int argc, char *argv[]) -> int {

    QApplication application(argc, argv);

    auto tests = std::list<std::shared_ptr<QObject>>{
        std::make_shared<QGUIFormTest>()
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