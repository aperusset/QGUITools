#include "qguicontainer.h"
#include <QApplication>

QGUIContainer::QGUIContainer(const unsigned int id, QWidget *parent) :
    QWidget(parent), id(id) {}

auto QGUIContainer::getId() const -> unsigned int {
    return this->id;
}

void QGUIContainer::wait() const {
    QApplication::setOverrideCursor(Qt::WaitCursor);
}

void QGUIContainer::finished() const {
    QApplication::restoreOverrideCursor();
}

void QGUIContainer::notify() const {
    emit notify(this->id);
}

void QGUIContainer::update() {
    this->updateButtons();
}
