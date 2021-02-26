#ifndef DECIMALDROPDOWN_H
#define DECIMALDROPDOWN_H

#include "intervaldropdown.h"

class DecimalDropDown : public IntervalDropDown<double> {

public:
    DecimalDropDown(const QString &labelText, const double min, const double max,
                    const double increment, const double defaultValue, QWidget *parent);
    auto buildDisplayValue(const double value) const -> QString override;

    static const unsigned int DISPLAY_PRECISON = 1; // TODO should be parametrizable ?
};

#endif // DECIMALDROPDOWN_H
