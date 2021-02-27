#include "qguicontainer.h"
#include <QApplication>

QGUIContainer::QGUIContainer(const unsigned int id, QWidget *parent) :
    QWidget(parent), id(id) {}

auto QGUIContainer::getId() const -> unsigned int {
    return this->id;
}

void QGUIContainer::wait() {
    QApplication::setOverrideCursor(Qt::WaitCursor);
}

void QGUIContainer::finished() {
    QApplication::restoreOverrideCursor();
}

void QGUIContainer::notify() {
    emit hasChanged(this->id);
}

void QGUIContainer::update() {
    this->updateButtons();
}
