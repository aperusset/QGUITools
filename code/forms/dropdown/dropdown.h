#ifndef DROPDOWN_H
#define DROPDOWN_H

#include <QComboBox>
#include <QVariant>
#include <QString>
#include <map>
#include "forms/qguiform.h"

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

    virtual auto data() -> std::map<QVariant, QString> = 0;

    static const int INVALID_SELECTED_INDEX = -1;
};

#endif  // DROPDOWN_H
