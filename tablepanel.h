#ifndef TABLEPANEL_H
#define TABLEPANEL_H

#include <QMainWindow>
#include<QTableWidget>
#include<QMap>
#include "student.h"

class TablePanel : public QWidget
{
    Q_OBJECT
public:
    explicit TablePanel(QWidget * parent = nullptr);
    void setUpUi();
    std::map<QString,Student> studentMap;
    void initStudent();

    void setCurrentUniversity(const QString &university){
        currentUniversity = university;
        currentCollege.clear();
    }
    void setCurrentCollege(const QString &college){
        currentCollege = college;
        // currentUniversity.clear();
    }

signals:
    void studentAdded();
public slots:
    void loadModule(const QString &modulname);
    void addStudentTotable(const Student &student);
    void onItemClicked(QTableWidgetItem *item);
private:
    QString currentUniversity;
    QString currentCollege;

    QTableWidget *tableWidget;
};

#endif // TABLEPANEL_H
