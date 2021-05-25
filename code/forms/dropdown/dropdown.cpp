#include "forms/dropdown/dropdown.h"

DropDown::DropDown(const QString &labelText, QWidget *parent) :
    QGUIForm(labelText, parent), comboBox(new QComboBox(this)),
    originalData(QVariant::Invalid), modified(false) {
    this->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(this->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [=] {
                emit hasChanged();
                this->modified = true;
            });
}

DropDown::~DropDown() {
    delete this->comboBox;
}

auto DropDown::setData(const QVariant &data) -> bool {
    auto const index = this->comboBox->findData(data);
    if (index != INVALID_SELECTED_INDEX) {
        this->comboBox->setCurrentIndex(index);
        return !(this->modified = false);
    }
    return false;
}

void DropDown::populate() {
    this->comboBox->blockSignals(true);
    auto const currentData = this->getData();
    auto const currentlyModified = this->isModified();
    this->comboBox->clear();
    for (auto const &element : this->data()) {
        this->comboBox->addItem(element.second, element.first);
    }
    this->comboBox->model()->sort(0);
    this->modified = !this->setData(currentData) || currentlyModified;
    this->comboBox->blockSignals(false);
}

auto DropDown::isModified() const -> bool {
    return this->modified;
}

auto DropDown::getWidget() const -> QWidget* {
    return this->comboBox;
}
