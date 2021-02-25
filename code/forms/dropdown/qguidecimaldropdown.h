#ifndef QGUIDECIMALDROPDOWN_H
#define QGUIDECIMALDROPDOWN_H

#include "qguiintervaldropdown.h"

class QGUIDecimalDropDown : public QGUIIntervalDropDown<double> {

public:
    QGUIDecimalDropDown(const QString &labelText, const double min, const double max,
                        const double increment, const double defaultValue, QWidget *parent);
    auto buildDisplayValue(const double value) const -> QString override;

    static const unsigned int DISPLAY_PRECISON = 1; // TODO should be parametrizable ?
};

#endif // QGUIDECIMALDROPDOWN_H
