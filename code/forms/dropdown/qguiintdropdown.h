#ifndef QGUIINTDROPDOWN_H
#define QGUIINTDROPDOWN_H

#include "qguiintervaldropdown.h"

class QGUIIntDropDown : public QGUIIntervalDropDown<int> {

public:
    QGUIIntDropDown(const QString &labelText, const int min, const int max,
                  const int increment, const int defaultValue, QWidget *parent);
    auto buildDisplayValue(const int value) const -> QString override;
};

#endif // QGUIINTDROPDOWN_H
