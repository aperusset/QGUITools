#include "decimaldropdown.h"

DecimalDropDown::DecimalDropDown(const QString &labelText, const double min, const double max, const double increment,
                                     const double defaultValue, QWidget *parent) :
    IntervalDropDown(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto DecimalDropDown::buildDisplayValue(const double value) const -> QString {
    return QString::number(value, 'f', DISPLAY_PRECISON);
}
