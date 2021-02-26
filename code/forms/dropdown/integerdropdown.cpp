#include "integerdropdown.h"

IntegerDropDown::IntegerDropDown(const QString &labelText, const int min, const int max, const int increment,
                             const int defaultValue, QWidget *parent) :
    IntervalDropDown(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto IntegerDropDown::buildDisplayValue(const int value) const -> QString {
    return QString::number(value);
}
