/*
 * VN-Office Source Code
 * Copyright (c) HuyMin
 * Author: HuyMin <nvminhhuy2202@gmail.com>
 * Licensed under the VN-Office License.
 *
*/

#ifndef CMENU_H
#define CMENU_H

#include <QWidget>
#include <QIcon>


class CMenuWidget;
class CMenu : public QObject
{
    Q_OBJECT
public:
    explicit CMenu(QWidget * parent = nullptr);
    ~CMenu();

    enum Action {
        ActionClose = 0,
        ActionCloseSaved,
        ActionCloseAll,
        ActionShowInFolder,
        ActionMoveToStart,
        ActionMoveToEnd,
        ActionUnpinTab,
        ActionPinToTab,
        ActionCreateNew,
        ACTION_COUNT
    };

    QAction* addSection(Action action, const QIcon &icon = QIcon());
    QAction* addSection(const QString &text, const QIcon &icon = QIcon());
    QAction* addSeparator();
    void setSectionIcon(Action action, const QIcon &icon);
    void setSectionEnabled(Action action, bool enabled);
    void exec(const QPoint &pos);

signals:
    void wasHidden();

private:
    static const char* m_actionText[ACTION_COUNT];
    QVector<QAction*> m_actions;
    CMenuWidget *m_menu_widget;
    QWidget *m_parent;
};

#endif // CMENU_H
