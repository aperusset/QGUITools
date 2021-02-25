#ifndef QGUIDECIMALSELECT_H
#define QGUIDECIMALSELECT_H

#include "qguiintervalselect.h"

class QGUIDecimalSelect : public QGUIIntervalSelect<double> {

public:
    QGUIDecimalSelect(const QString &labelText, const double min, const double max,
                      const double increment, const double defaultValue, QWidget *parent);
    auto buildDisplayValue(const double value) const -> QString override;
};

#endif // QGUIDECIMALSELECT_H
