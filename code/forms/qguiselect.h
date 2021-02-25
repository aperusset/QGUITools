#ifndef QGUISELECT_H
#define QGUISELECT_H

#include "qguiform.h"
#include <QComboBox>
#include <QVariant>
#include <QString>
#include <map>

class QGUISelect : public QGUIForm {

    QComboBox *comboBox;

public:
    QGUISelect(const QString &labelText, QWidget *parent);
    ~QGUISelect();

    template<typename T = QVariant>
    auto getData() const -> T {
        return this->comboBox->currentData().value<T>();
    }
    void setData(const QVariant&);
    void adjustToContent();
    virtual void populate();
    auto getWidget() const -> QWidget* override;

    virtual auto datas() -> std::map<QVariant, QString> = 0;

    static const int INVALID_SELECTED_INDEX = -1;

};

#endif // QGUISELECT_H
