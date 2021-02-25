#ifndef QGUIFORM_H
#define QGUIFORM_H

#include <QWidget>
#include <QLabel>

class QGUIForm : public QWidget {

    Q_OBJECT

    QLabel *label;

    static const QString LABEL_TEXT_SUFFIX;

public:
    QGUIForm(const QString &labelText, QWidget *parent);
    ~QGUIForm();
    auto getLabel() const -> QLabel*;
    void setLabelText(const QString&);
    void enable();
    void disable();
    void setEnabled(const bool enabled);
    auto isEnabled() const -> bool;
    void focus() const;
    void show();
    void hide();

    virtual auto getWidget() const -> QWidget* = 0;

public slots:
    void changed(const QString &value);
    void changedByUser(const QString &value);

signals:
    void hasChanged(const QString &value);
    void userHasChanged(const QString &value);
};

#endif // QGUIFORM_H
