#include "qguiintselect.h"

QGUIIntSelect::QGUIIntSelect(const QString &labelText, const int min, const int max, const int increment,
                             const int defaultValue, QWidget *parent) :
    QGUIIntervalSelect(labelText, min, max, increment, parent) {
    this->setData(defaultValue);
}

auto QGUIIntSelect::buildDisplayValue(const int value) const -> QString {
    return QString::number(value);
}
