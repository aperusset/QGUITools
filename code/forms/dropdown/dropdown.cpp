#include "dropdown.h"

DropDown::DropDown(const QString &labelText, QWidget *parent) :
    QGUIForm(labelText, parent), comboBox(new QComboBox(this)) {
    this->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(this->comboBox, SIGNAL(currentIndexChanged(QString&)), this, SLOT(changed(QString&)));
    connect(this->comboBox, SIGNAL(activated(QString&)), this, SLOT(userHasChanged(QString&)));
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
    auto const currentData = this->getData<>();
    this->comboBox->clear();
    for (auto const &element : this->data()) {
        this->comboBox->addItem(element.second, element.first);
    }
    this->setData(currentData);
    this->comboBox->model()->sort(0);
}

auto DropDown::getWidget() const -> QWidget* {
    return this->comboBox;
}
