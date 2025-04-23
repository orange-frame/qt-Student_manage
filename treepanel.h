#ifndef TREEPANEL_H
#define TREEPANEL_H

#include <QWidget>
#include <QTreeWidget>
#include<QMenu>
#include "student.h"

class TreePanel : public QWidget
{
    Q_OBJECT
public:
    explicit TreePanel(QWidget *parent = nullptr);

signals:
    void moduleSelected(const QString &moduleName);
    void universitySelected(const QString &uniName);
    void collegeSelecte(const QString &collName);
    void addStudentToTable(const Student& student);
private slots:
    void onItemClicked(QTreeWidgetItem *item,int column);
    void showContextMenu(const QPoint &pos);

    void removeItem();

    void initTreeWidget();


    void addUniversity();
    void addItem();  //添加学院
    void addStudent();  //添加学生
    void addTeacher();  //添加教师
    // void addTeache();
private:
    QTreeWidget *treeWidget;
    QMenu *contextMenu;
    QMenu *blackMenu;
    QMenu *Menu;
    QTreeWidgetItem *currentItem;
    QTreeWidgetItem *universityItem;
    QTreeWidgetItem *colledgeItem;
    QString currentCollegeName;
};

#endif // TREEPANEL_H
