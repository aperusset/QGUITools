#include "qguidecimalselect.h"

QGUIDecimalSelect::QGUIDecimalSelect(const QString &labelText, const double min, const double max, const double increment,
                                     const double defaultValue, QWidget *parent) :
    QGUIIntervalSelect(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto QGUIDecimalSelect::buildDisplayValue(const double value) const -> QString {
    return QString::number(value, 'f', 1);
}
