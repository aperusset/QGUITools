#include "forms/dropdown/decimaldropdown.h"
#include <string>
DecimalDropDown::DecimalDropDown(const QString &labelText, const double min,
                                 const double max, const double increment,
                                 const double defaultValue, QWidget *parent) :
    DecimalDropDown(labelText, min, max, increment, defaultValue,
                    DEFAULT_DISPLAY_PRECISON, parent) {}

DecimalDropDown::DecimalDropDown(const QString &labelText, const double min,
                                 const double max, const double increment,
                                 const double defaultValue,
                                 const unsigned int displayPrecision,
                                 QWidget *parent) :
    IntervalDropDown(labelText, min, max, increment, parent),
    displayPrecision(displayPrecision) {
    if (this->displayPrecision < 1) {
        throw std::string("Display precision must be >= 1");
    }
    this->setData(defaultValue);
}

auto DecimalDropDown::getDisplayPrecision() -> unsigned int {
    return this->displayPrecision;
}

auto DecimalDropDown::buildDisplayValue(const double value) const -> QString {
    return QString::number(value, 'f', this->displayPrecision);
}
