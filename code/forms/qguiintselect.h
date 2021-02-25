#ifndef QGUIINTSELECT_H
#define QGUIINTSELECT_H

#include "qguiintervalselect.h"

class QGUIIntSelect : public QGUIIntervalSelect<int> {

public:
    QGUIIntSelect(const QString &labelText, const int min, const int max,
                  const int increment, const int defaultValue, QWidget *parent);
    auto buildDisplayValue(const int value) const -> QString override;
};

#endif // QGUIINTSELECT_H
