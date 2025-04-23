#include "treepanel.h"
#include "addStudentdialog.h"
#include "addTeacherdialog.h"  // 确保包含了 AddTeacherDialog 的头文件


#include"student.h"
#include <QVBoxLayout>
#include <QAction>
#include <QInputDialog>

TreePanel::TreePanel(QWidget *parent)
    : QWidget{parent}
{
    initTreeWidget();
}

void TreePanel::onItemClicked(QTreeWidgetItem *item, int column)
{
    QString name = item->text(0);
    if(item->parent()== nullptr && name.contains("大学"))
    {
        emit universitySelected(name);
        emit moduleSelected("学生列表");
    }
    else if(item->parent() && item->parent()->text(0).contains("大学")){
        emit collegeSelecte(name);
        emit moduleSelected("学生列表");
    }
}

void TreePanel::showContextMenu(const QPoint &pos)
{
    currentItem = treeWidget->itemAt(pos);
    QPoint globalPos = treeWidget->viewport()->mapToGlobal(pos);
    if (currentItem == nullptr) {
        blackMenu->exec(globalPos);  // 右键空白区域
        return;
    }
    QString nodeType = currentItem->data(0, Qt::UserRole).toString(); // 获取节点类型
    qDebug()<< nodeType;
    // 根据节点类型展示不同的菜单
    if (nodeType == "teacher") {
        QMenu *teacherMenu = new QMenu(this);
        teacherMenu->addAction("添加老师", this,&TreePanel::addTeacher);
        teacherMenu->exec(globalPos);
    } else if (nodeType == "student") {
        QMenu *studentMenu = new QMenu(this);
        studentMenu->addAction("添加学生", this, &TreePanel::addStudent);
        studentMenu->exec(globalPos);
    }
    else if (nodeType == "university") {
        contextMenu->exec(globalPos); // 学校节点菜单
    }
    else if (nodeType == "college") {
        currentCollegeName = currentItem->text(0);
        QMenu *collegeMenu = new QMenu(this);
        collegeMenu->addAction("添加教师",this,&TreePanel::addTeacher);
        collegeMenu->addAction("添加学生",this,&TreePanel::addStudent);
        collegeMenu->addAction("删除当前学院",this,&TreePanel::removeItem);
        collegeMenu->exec(globalPos); // 学院节点菜单

    }else {
        contextMenu->exec(globalPos);  // 其他节点菜单
    }
}


void TreePanel::addItem()
{
    if(!currentItem) return ;
    if(currentItem == colledgeItem) return ;
    bool ok;
    QString text = QInputDialog::getText(this,"添加学院","学院名称",QLineEdit::Normal,"",&ok);
    if(ok && !text.isEmpty()){
        QTreeWidgetItem *newItem = new QTreeWidgetItem(currentItem);
        newItem->setData(0,Qt::UserRole,"college");
        newItem->setText(0,text);

        if(currentItem->data(0,Qt::UserRole).toString() == "university"){
            QTreeWidgetItem *teacherItem = new QTreeWidgetItem(newItem);
            teacherItem->setData(0,Qt::UserRole,"teacher");
            teacherItem->setText(0,"教师列表");

            QTreeWidgetItem *studentItem = new QTreeWidgetItem(newItem);
            studentItem->setData(0,Qt::UserRole,"student");
            studentItem->setText(0,"学生列表");
        }
        currentItem->setExpanded(true);
    }
}


void TreePanel::removeItem()
{
    if(!currentItem) return;
    if(currentItem->parent() == nullptr){
        delete currentItem;
    }
    else{
    QTreeWidgetItem *parent = currentItem->parent();
    parent->removeChild(currentItem);
    delete currentItem;
    }
    currentItem = nullptr;
}

void TreePanel::initTreeWidget()
{
    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderHidden(true);
    treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    universityItem = new QTreeWidgetItem(treeWidget);
    universityItem->setText(0,"清华大学");
    universityItem->setData(0,Qt::UserRole,"university");

    colledgeItem = new QTreeWidgetItem(universityItem);
    colledgeItem->setText(0,"计算机学院");
    colledgeItem->setData(0,Qt::UserRole,"college");



    QTreeWidgetItem *teacherItem = new QTreeWidgetItem(colledgeItem);
    teacherItem->setText(0,"教师列表");
    teacherItem->setData(0,Qt::UserRole,"teacher");


    QTreeWidgetItem *studentItem = new QTreeWidgetItem(colledgeItem);
    studentItem->setText(0,"学生列表");
    studentItem->setData(0,Qt::UserRole,"student");

    connect(treeWidget,&QTreeWidget::itemClicked,this,&TreePanel::onItemClicked);
    connect(treeWidget,&QTreeWidget::customContextMenuRequested,this,&TreePanel::showContextMenu);



    contextMenu = new QMenu(this);
    contextMenu->addAction("添加学院",this,&TreePanel::addItem);
    contextMenu->addAction("删除学校",this,&TreePanel::removeItem);

    blackMenu = new QMenu(this);
    blackMenu->addAction("创建学校",this,&TreePanel::addUniversity);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(treeWidget);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}

void TreePanel::addUniversity()
{
    bool ok;
    QString text = QInputDialog::getText(this,"创建学校","学校名称",QLineEdit::Normal,"",&ok);
    if(ok && !text.isEmpty()){
        QTreeWidgetItem *newUniverse = new QTreeWidgetItem(treeWidget);
        newUniverse->setData(0,Qt::UserRole,"university");
        newUniverse->setText(0,text);
        treeWidget->setCurrentItem(newUniverse);
    }
}

void TreePanel::addStudent()
{
    AddStudentDialog dialog(currentCollegeName,this);
    if (dialog.exec() == QDialog::Accepted) {
        // 获取用户输入的学生信息
        QString studentId = dialog.studentId();
        QString studentName = dialog.studentName();
        QString sex = dialog.studentSex();
        double height = dialog.studentHeight();
        QString college = dialog.studentCollege();

        Student newStudent(studentId,studentName,sex,height,college,universityItem->text(0),":/images/1");

        emit addStudentToTable(newStudent);
    }
}
void TreePanel::addTeacher() {
    AddTeacherDialog dialog(currentCollegeName,this);// 使用当前学院名称作为默认值
    if (dialog.exec() == QDialog::Accepted) {
        // 获取用户输入的教师信息
        QString teacherId = dialog.studentId();  // 这里获取的是工号
        QString teacherName = dialog.studentName();
        QString sex = dialog.studentSex();
        double height = dialog.studentHeight();
        QString college = dialog.studentCollege();
        // 创建教师对象并处理（你可以将其添加到对应的容器）
        qDebug() << "添加教师：" << teacherId << teacherName << sex << height << college;

        // 在这里你可以发射信号或者进一步处理教师数据
        // 例如：emit addTeacherToTable(newTeacher);
    }
}

