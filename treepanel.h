#ifndef TREEPANEL_H
#define TREEPANEL_H

#include <QWidget>
#include <QTreeWidget>
#include<QMenu>

class TreePanel : public QWidget
{
    Q_OBJECT
public:
    explicit TreePanel(QWidget *parent = nullptr);

signals:
    void moduleSelected(const QString &moduleName);
private slots:
    void onItemClicked(QTreeWidgetItem *item,int column);
    void showContextMenu(const QPoint &pos);
    void addItem();
    void removeItem();
    void initTreeWidget();
    void addUniversity();
private:
    QTreeWidget *treeWidget;
    QMenu *contextMenu;
    QMenu *blackMenu;
    QMenu *Menu;
    QTreeWidgetItem *currentItem;
    QTreeWidgetItem *universityItem;
    QTreeWidgetItem *colledgeItem;
};

#endif // TREEPANEL_H
