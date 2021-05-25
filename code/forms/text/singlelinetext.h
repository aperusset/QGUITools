#ifndef SINGLELINETEXT_H
#define SINGLELINETEXT_H

#include <QLineEdit>
#include "forms/qguiform.h"
#include "forms/validator/validator.h"

class SingleLineText : public QGUIForm {
    QLineEdit* const lineEdit;
    const Validator* const validator;

 public:
    SingleLineText(const QString &labelText, const bool mandatory,
                   QWidget *parent);
    SingleLineText(const QString &labelText, const Validator *validator,
                   QWidget *parent);
    ~SingleLineText();
    auto getLineEdit() const -> const QLineEdit&;
    auto getValidator() const -> const Validator&;
    auto getText() const -> QString;
    void setText(const QString&);
    auto isReadOnly() const -> bool;
    void setReadOnly(const bool);
    void setWidth(const int);
    void setEchoMode(const QLineEdit::EchoMode);

    auto isModified() const -> bool override;
    auto isValid() const -> bool override;
    auto getWidget() const -> QWidget* override;

    static const int DEFAULT_FIELD_WIDTH = 150U;

    // TODO to be implemented as subclasses : Integer / Decimal / Mail / Phone
    // TODO questionnable : QGUIDate (or/and a calendar widget ?)
    // TODO in which categories ? Completer / Checkbox
    // TODO activable QGUIForm with a checkbox and nested QGUIForm ?
    // https://doc.qt.io/qt-5/qt.html#DateFormat-enum
    // https://doc.qt.io/qt-5/qlocale.html#system
    // https://doc.qt.io/qt-5/qlocale.html#dateFormat
    // https://doc.qt.io/qt-5/qbuttongroup.html
};

#endif  // SINGLELINETEXT_H
