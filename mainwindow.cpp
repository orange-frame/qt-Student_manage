#include "mainwindow.h"
#include"treepanel.h"
#include"tablepanel.h"

#include<QSplitter>
#include<QIcon>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    treePanel = new TreePanel(this);
    tablePanel = new TablePanel(this);
    this->setWindowIcon(QIcon(":/images/system"));

    spliter = new QSplitter(this);
    spliter->addWidget(treePanel);
    spliter->addWidget(tablePanel);

    spliter->setStretchFactor(1,1);

    setCentralWidget(spliter);
    setWindowTitle("学校管理系统");
    resize(1000,600);

    connect(treePanel,&TreePanel::moduleSelected,tablePanel,&TablePanel::loadModule);


    connect(treePanel,&TreePanel::universitySelected,this,[=](const QString &uniName){
        tablePanel->setCurrentUniversity(uniName);
        tablePanel->loadModule("学生列表");
    });
    connect(treePanel,&TreePanel::collegeSelecte,this,[=](const QString &collname){
        tablePanel->setCurrentCollege(collname);
        tablePanel->loadModule("学生列表");
    });
    connect(treePanel,&TreePanel::addStudentToTable,tablePanel,&TablePanel::addStudentTotable);
}
