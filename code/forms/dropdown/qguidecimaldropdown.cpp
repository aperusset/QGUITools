#include "qguidecimaldropdown.h"

QGUIDecimalDropDown::QGUIDecimalDropDown(const QString &labelText, const double min, const double max, const double increment,
                                     const double defaultValue, QWidget *parent) :
    QGUIIntervalDropDown(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto QGUIDecimalDropDown::buildDisplayValue(const double value) const -> QString {
    return QString::number(value, 'f', DISPLAY_PRECISON);
}
