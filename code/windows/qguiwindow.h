#ifndef QGUIWINDOW_H
#define QGUIWINDOW_H

#include "qguicontainer.h"
#include <QDialog>
#include <QLayout>

class QGUIWindow : public QGUIContainer {

    QDialog *dialog;

public:
    QGUIWindow(const unsigned int id, const QString &title, QWidget *parent);
    ~QGUIWindow();
    auto getTitle() const -> QString override;
    void setTitle(const QString &title) override;
    void setMainLayout(QLayout *mainLayout);
    virtual auto exec() -> QDialog::DialogCode;
};

#endif // QGUIWINDOW_H
