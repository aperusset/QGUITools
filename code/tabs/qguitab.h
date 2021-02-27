#ifndef QGUITAB_H
#define QGUITAB_H

#include "qguicontainer.h"

class QGUITab : public QGUIContainer {

    Q_OBJECT

    QString title;
    const unsigned int instanceId;
    bool modified;

public:
    QGUITab(const unsigned int id, const QString &title, QWidget *parent);
    QGUITab(const unsigned int id, const unsigned int instanceId, QString title, QWidget *parent);
    auto getTitle() const -> QString override;
    void setTitle(const QString &title) override;
    auto getInstanceId() const -> unsigned int;
    auto isModified() const -> bool;
    void setModified(const bool modified);
    void reset() override;

    static const int INVALID_SELECTED_VALUE = -1;
    static const unsigned int DEFAULT_TAB_LINE_HEIGHT = 20;
    static const unsigned int TAB_ID_COLUMN = 0;
    static const unsigned int UNIQUE_INSTANCE_ID = 0;

signals:
    void changeTitle(QGUITab&, const QString &title);
    void closeTab(QGUITab&);
};

#endif // QGUITAB_H
