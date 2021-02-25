#ifndef QGUIDROPDOWN_H
#define QGUIDROPDOWN_H

#include "forms/qguiform.h"
#include <QComboBox>
#include <QVariant>
#include <QString>
#include <map>

class QGUIDropDown : public QGUIForm {

    QComboBox *comboBox;

public:
    QGUIDropDown(const QString &labelText, QWidget *parent);
    ~QGUIDropDown();

    template<typename T = QVariant>
    auto getData() const -> T {
        return this->comboBox->currentData().value<T>();
    }
    void setData(const QVariant&);
    virtual void populate();
    auto getWidget() const -> QWidget* override;

    virtual auto datas() -> std::map<QVariant, QString> = 0;

    static const int INVALID_SELECTED_INDEX = -1;
};

#endif // QGUIDROPDOWN_H
