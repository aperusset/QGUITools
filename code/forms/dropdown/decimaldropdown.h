#ifndef DECIMALDROPDOWN_H
#define DECIMALDROPDOWN_H

#include "forms/dropdown/intervaldropdown.h"

class DecimalDropDown : public IntervalDropDown<double> {
    const unsigned int displayPrecision;

 public:
    DecimalDropDown(const QString &labelText, const double min,
                    const double max, const double increment,
                    const double defaultValue, QWidget *parent);
    DecimalDropDown(const QString &labelText, const double min,
                    const double max, const double increment,
                    const double defaultValue,
                    const unsigned int displayPrecision, QWidget *parent);
    auto getDisplayPrecision() -> unsigned int;
    auto buildDisplayValue(const double value) const -> QString override;

    static const unsigned int DEFAULT_DISPLAY_PRECISON = 1;
};

#endif  // DECIMALDROPDOWN_H
