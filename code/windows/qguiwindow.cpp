#include "qguiwindow.h"

QGUIWindow::QGUIWindow(const unsigned int id, const QString &title, QWidget *parent) :
    QGUIContainer(id, parent), dialog(new QDialog(this)) {
    this->dialog->setWindowTitle(title);
}

QGUIWindow::~QGUIWindow() {
    delete this->dialog;
}

auto QGUIWindow::getTitle() const -> QString {
    return this->dialog->windowTitle();
}

void QGUIWindow::setTitle(const QString &title) {
    this->dialog->setWindowTitle(title);
}

void QGUIWindow::setMainLayout(QLayout *mainLayout) {
    mainLayout->setParent(this->dialog);
}

auto QGUIWindow::exec() -> QDialog::DialogCode {
    return (QDialog::DialogCode)this->dialog->exec();
}
