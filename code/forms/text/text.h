#ifndef TEXT_H
#define TEXT_H

#include "forms/qguiform.h"
#include <QLineEdit>
#include <QRegExp>
#include <QColor>

class Text : public QGUIForm {

    bool mandatory;
    QLineEdit *lineEdit;
    QRegExp *validator;

public:
    Text(const QString &labelText, const bool mandatory, QWidget *parent);
    Text(const QString &labelText, const bool mandatory, const unsigned int width, QWidget *parent);
    Text(const QString &labelText, const bool mandatory, const unsigned int width, QRegExp *validator, QWidget *parent);
    Text(const QString &labelText, const bool mandatory, const QString &defaultValue, QWidget *parent);
    Text(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QWidget *parent);
    Text(const QString &labelText, const bool mandatory, const QString &defaultValue, const unsigned int width, QRegExp *validator, QWidget *parent);
    ~Text();
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

    // TODO to be implemented as subclasses : QGUIDecimalText / QGUIIntText / QGUIMailText / QGUIPhoneText
    // TODO questionnable : QGUIDate (or/and a calendar widget ?)
    // TODO in which categories ? QGUICompleter / QGUICheckbox / QGUIComb
    // TODO activable QGUIForm with a checkbox and nested QGUIForm ?
    // https://doc.qt.io/qt-5/qt.html#DateFormat-enum
    // https://doc.qt.io/qt-5/qlocale.html#system
    // https://doc.qt.io/qt-5/qlocale.html#dateFormat
    // https://doc.qt.io/qt-5/qbuttongroup.html
};

#endif // TEXT_H
