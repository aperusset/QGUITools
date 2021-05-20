#include "forms/dropdown/dropdown.h"

DropDown::DropDown(const QString &labelText, QWidget *parent) :
    QGUIForm(labelText, parent), comboBox(new QComboBox(this)) {
    this->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(this->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &QGUIForm::hasChanged);
}

DropDown::~DropDown() {
    delete this->comboBox;
}

void DropDown::setData(const QVariant &data) {
    const int index = this->comboBox->findData(data);
    if (index != INVALID_SELECTED_INDEX) {
        this->comboBox->setCurrentIndex(index);
    }
}

void DropDown::populate() {
    this->comboBox->blockSignals(true);
    auto const currentData = this->getData<>();
    this->comboBox->clear();
    for (auto const &element : this->data()) {
        this->comboBox->addItem(element.second, element.first);
    }
    this->comboBox->model()->sort(0);
    this->setData(currentData);
    this->comboBox->blockSignals(false);
}

auto DropDown::getWidget() const -> QWidget* {
    return this->comboBox;
}
