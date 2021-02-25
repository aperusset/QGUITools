#include "qguiselect.h"

QGUISelect::QGUISelect(const QString &labelText, QWidget *parent) :
    QGUIForm(labelText, parent), comboBox(new QComboBox(this)) {
    connect(this->comboBox, SIGNAL(currentIndexChanged(QString&)), this, SLOT(changed(QString&)));
    connect(this->comboBox, SIGNAL(activated(QString&)), this, SLOT(userHasChanged(QString&)));
}

QGUISelect::~QGUISelect() {
    delete this->comboBox;
}

void QGUISelect::setData(const QVariant &data) {
    const int index = this->comboBox->findData(data);
    if (index != INVALID_SELECTED_INDEX) {
        this->comboBox->setCurrentIndex(index);
    }
}

void QGUISelect::adjustToContent() {
    this->comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

void QGUISelect::populate() {
    auto const currentData = this->getData<>();
    this->comboBox->clear();
    for (auto const &element : this->datas()) {
        this->comboBox->addItem(element.second, element.first);
    }
    this->setData(currentData);
    this->comboBox->model()->sort(0);
}

auto QGUISelect::getWidget() const -> QWidget* {
    return this->comboBox;
}
