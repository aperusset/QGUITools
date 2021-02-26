#ifndef TESTDROPDOWN_H
#define TESTDROPDOWN_H

#include "forms/dropdown/dropdown.h"

class TestDropDown : public DropDown {

    std::map<QVariant, QString> realData;

public:
    explicit TestDropDown(const QString &labelText) : DropDown(labelText, nullptr) {}

    auto data() -> std::map<QVariant, QString> override {
        return realData;
    }

    void setRealData(const std::map<QVariant, QString> &realData) {
        this->realData = realData;
        this->populate();
    }
};

#endif // TESTDROPDOWN_H
