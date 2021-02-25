#ifndef QGUITEXT_H
#define QGUITEXT_H

#include "forms/qguiform.h"
#include <QLineEdit>
#include <QRegExp>
#include <QColor>

class QGUIText : public QGUIForm {

    bool mandatory;
    QLineEdit *lineEdit;
    QRegExp *validator;

public:
    QGUIText(const QString &labelText, const bool mandatory, QWidget *parent);
    QGUIText(const QString &labelText, const bool mandatory, const unsigned int width, QWidget *parent);
    QGUIText(const QString &labelText, const bool mandatory, const unsigned int width, QRegExp *validator, QWidget *parent);
    QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, QWidget *parent);
    QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QWidget *parent);
    QGUIText(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QRegExp *validator, QWidget *parent);
    ~QGUIText();
    auto isMandatory() const -> bool;
    void setMandatory(const bool);
    auto isValid() const -> bool;
    auto getValue() const -> QString;
    void setValue(const QString&);
    auto isReadOnly() const -> bool;
    void setReadOnly(const bool);

    auto getWidget() const -> QWidget* override;

    static const QColor VALID_COLOR;
    static const QColor INVALID_COLOR;
    static const unsigned int DEFAULT_FIELD_WIDTH = 150;
    static const QString DEFAULT_REGEXP;
};

#endif // QGUITEXT_H
