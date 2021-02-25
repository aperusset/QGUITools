#include "qguiintdropdown.h"

QGUIIntDropDown::QGUIIntDropDown(const QString &labelText, const int min, const int max, const int increment,
                             const int defaultValue, QWidget *parent) :
    QGUIIntervalDropDown(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto QGUIIntDropDown::buildDisplayValue(const int value) const -> QString {
    return QString::number(value);
}
