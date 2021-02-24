#include "qguitab.h"

QGUITab::QGUITab(const unsigned int id, const unsigned int instanceId, QString title, QWidget *parent):
    QGUIContainer(id, parent), title(std::move(title)), instanceId(instanceId), modified(false) {

}

auto QGUITab::getTitle() const -> QString {
    return this->title;
}

void QGUITab::setTitle(const QString &title) {
    this->title = title;
}

auto QGUITab::getInstanceId() const -> unsigned int {
    return this->instanceId;
}

auto QGUITab::isModified() const -> bool {
    return this->modified;
}

void QGUITab::setModified(const bool modified) {
    this->modified = modified;
}

void QGUITab::reset() {
    this->setModified(false);
    QGUIContainer::reset();
}
