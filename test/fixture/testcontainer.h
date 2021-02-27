#ifndef TESTCONTAINER_H
#define TESTCONTAINER_H

#include "qguicontainer.h"

class TestContainer : public QGUIContainer {

    QString title;
    bool buttonsUpdated = false;

public:
    explicit TestContainer(QString title) :
        QGUIContainer(DEFAULT_ID, nullptr),
        title(std::move(title)) {};

    auto buttonsAreUpdated() const -> bool {
        return this->buttonsUpdated;
    }

    auto getTitle() const -> QString override {
        return this->title;
    };

    void setTitle(const QString &title) override {
        this->title = title;
    }

    void reset() override {}

    void updateButtons() override {
        this->buttonsUpdated = true;
    };

    static const unsigned int DEFAULT_ID = 42;
};

#endif // TESTCONTAINER_H
