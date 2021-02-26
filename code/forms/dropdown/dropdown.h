#ifndef DROPDOWN_H
#define DROPDOWN_H

#include "forms/qguiform.h"
#include <QComboBox>
#include <QVariant>
#include <QString>
#include <map>

class DropDown : public QGUIForm {

    QComboBox *comboBox;

public:
    DropDown(const QString &labelText, QWidget *parent);
    ~DropDown();

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

#endif // DROPDOWN_H
