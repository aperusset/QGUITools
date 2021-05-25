#ifndef QGUIFORM_H
#define QGUIFORM_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>

class QGUIForm : public QWidget {
    Q_OBJECT

    QLabel* const label;

 public:
    QGUIForm(const QString &labelText, QWidget *parent);
    ~QGUIForm();
    auto getLabel() const -> const QLabel&;
    void setLabelText(const QString&);

    virtual void enable();
    virtual void disable();
    virtual void setEnabled(const bool);
    virtual auto isEnabled() const -> bool;
    virtual auto isModified() const -> bool;
    virtual auto isValid() const -> bool;
    virtual void validate();
    virtual void focus() const;
    virtual void addTo(QFormLayout&);

    virtual auto getWidget() const -> QWidget* = 0;

    static const QString LABEL_TEXT_SUFFIX;

 signals:
    void hasChanged();
    void userHasChanged();
};

#endif  // QGUIFORM_H
