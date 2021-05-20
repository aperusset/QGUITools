#ifndef INTEGERDROPDOWN_H
#define INTEGERDROPDOWN_H

#include "forms/dropdown/intervaldropdown.h"

class IntegerDropDown : public IntervalDropDown<int> {
 public:
    IntegerDropDown(const QString &labelText, const int min, const int max,
                    const int increment, const int defaultValue,
                    QWidget *parent);
    auto buildDisplayValue(const int value) const -> QString override;
};

#endif  // INTEGERDROPDOWN_H
