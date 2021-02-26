#ifndef INTERVALDROPDOWN_H
#define INTERVALDROPDOWN_H

#include "dropdown.h"

template<typename T>
class IntervalDropDown : public DropDown {

    const T min;
    const T max;
    const T increment;

public:
    IntervalDropDown(const QString &labelText, T min, T max, T increment, QWidget *parent) :
        DropDown(labelText, parent), min(std::move(min)), max(std::move(max)), increment(std::move(increment)) {
        if (this->min > this->max) {
            throw std::string("min must be lower or equals to max.");
        }
        if (this->min + this->increment <= this->min) {
            throw std::string("increment must effectively increase");
        }
    }

    auto getData() -> T {
        return DropDown::getData<T>();
    }

    auto data() -> std::map<QVariant, QString> override {
        std::map<QVariant, QString> values;
        for (auto value = this->min; value <= this->max; value += this->increment) {
            values.insert(std::make_pair(buildValue(value), buildDisplayValue(value)));
        }
        return values;
    }

    virtual auto buildValue(const T value) const -> QVariant {
        return QVariant(value);
    }

    virtual auto buildDisplayValue(const T value) const -> QString = 0;
};

#endif // INTERVALDROPDOWN_H
