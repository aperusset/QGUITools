#ifndef QGUICONTAINER_H
#define QGUICONTAINER_H

#include <QWidget>
#include <QString>

class QGUIContainer : public QWidget {

    Q_OBJECT

    const unsigned int id;

public:
    QGUIContainer(const unsigned int id, QWidget *parent);
    auto getId() const -> unsigned int;
    virtual auto getTitle() const -> QString = 0;

public slots:
    virtual void wait();
    virtual void finished();
    virtual void notify();
    virtual void update();

    virtual void setTitle(const QString&) = 0;
    virtual void reset() = 0;
    virtual void updateButtons() = 0;

signals:
    void hasChanged(const unsigned int);
    void newMessage(const QString&);
};

#endif // QGUICONTAINER_H
