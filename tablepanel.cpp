#include "tablepanel.h"
#include"detaildialog.h"
#include<QTabWidget>
#include<QWidget>
#include<QHeaderView>
#include<QVBoxLayout>
#include<QDebug>
#include<QMessageBox>
#include<QPixmap>

TablePanel::TablePanel(QWidget *parent)
    : QWidget(parent)
{
    setUpUi();
    initStudent();
    connect(tableWidget,&QTableWidget::itemClicked,this,&TablePanel::onItemClicked);
}

void TablePanel::setUpUi()
{
    tableWidget= new QTableWidget(this);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->verticalHeader()->setVisible(true);
    tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    layout->setContentsMargins(0,0,0,0);
    setLayout(layout);
}
//初始化学生列表
void TablePanel::initStudent() {
    studentMap["S001"] = Student("S001", "张三", "男", 175.5, "计算机学院","清华大学",":/images/1");
    studentMap["S002"] = Student("S002", "李四", "女", 160.0, "计算机学院","清华大学",":/images/1");
    studentMap["S003"] = Student("S003", "王五", "男", 180.2, "计算机学院","北京大学",":/images/1");
    QPixmap pix(":/images/1");
}

void TablePanel::loadModule(const QString &moduleName) {
    tableWidget->clearContents();

    QStringList headers;

    if (moduleName.contains("学生")) {
        if(!currentCollege.isEmpty()){
            headers = {"学号", "姓名", "性别", "身高", "所属学院"};
        }
        else if(!currentUniversity.isEmpty()){
            headers = {"学号", "姓名", "性别", "身高", "所属学院","大学"};
        }
        else{
            headers = {"学号", "姓名", "性别", "身高", "所属学院","大学"};
        }


        // 设置表格的列数和表头
        tableWidget->setColumnCount(headers.size());
        tableWidget->setHorizontalHeaderLabels(headers);


        //清空表格数据
        tableWidget->setRowCount(0);

        qDebug()<<headers;
        int row =0;
        for(const auto &entry:studentMap){
            const Student &student = entry.second;

            if(!currentUniversity.isEmpty() && student.university != currentUniversity)
                continue;
            if(!currentCollege.isEmpty() && student.college != currentCollege) continue;

            tableWidget->insertRow(row);
            tableWidget->setItem(row,0,new QTableWidgetItem(student.s_id));
            tableWidget->setItem(row,1,new QTableWidgetItem(student.name));
            tableWidget->setItem(row,2,new QTableWidgetItem(student.sex));
            tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(student.height)));
            if(student.university == currentUniversity){
                tableWidget->setItem(row,4,new QTableWidgetItem(student.college));
            }

            if (currentCollege.isEmpty() || !currentUniversity.isEmpty()) {
                tableWidget->setItem(row, headers.size() - 1, new QTableWidgetItem(student.university));
            }
            row++;
        }
    }
}

void TablePanel::addStudentTotable(const Student &student)
{
    studentMap[student.s_id] = student;
    emit studentAdded();
}

void TablePanel::onItemClicked(QTableWidgetItem *item)
{
    int row = item->row();
    QString student_id = tableWidget->item(row,0)->text();

    if(studentMap.find(student_id)!=studentMap.end()){
        Student student = studentMap[student_id];
        DetailDialog dialog(student,this);
        dialog.exec();
    }
    else{
        QMessageBox::warning(this,"警告","未查到学生信息",QMessageBox::Ok);
    }
}

