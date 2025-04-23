#include "detaildialog.h"

#include<QPushButton>
#include<QVBoxLayout>
#include<QLabel>
#include<QDebug>
DetailDialog::DetailDialog(const Student &student, QWidget *parent)
    :QDialog(parent)
{
    setWindowTitle("学生详细信息");
    idEdit = new QLineEdit(student.s_id);
    nameEdit = new QLineEdit(student.name);
    sexCombo = new QComboBox();
    sexCombo->addItem("男");
    sexCombo->addItem("女");
    sexCombo->setCurrentText(student.sex);
    heightEdit = new QLineEdit(QString::number(student.height));
    collegeEdit = new QLineEdit(student.college);
    universityEdit = new QLineEdit(student.university);
    avatarLabel = new QLabel(this);
    avatarLabel->resize(50,60);
    if(!student.avatarPath.isEmpty()){
        QPixmap pic(student.avatarPath);
        if(pic.isNull()){
            qDebug()<<"hello";
        }
        avatarLabel->setPixmap(pic);
    }
    else {
        avatarLabel->setText("图片加载失败");
    }
    saveButton = new QPushButton("保存",this);
    cancelButton = new QPushButton("取消",this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(avatarLabel);

    layout->addWidget(new QLabel("学号"));
    layout->addWidget(idEdit);

    layout->addWidget(new QLabel("姓名"));
    layout->addWidget(nameEdit);

    layout->addWidget(new QLabel("性别"));
    layout->addWidget(sexCombo);

    layout->addWidget(new QLabel("身高"));
    layout->addWidget(heightEdit);

    layout->addWidget(new QLabel("学院"));
    layout->addWidget(collegeEdit);

    layout->addWidget(new QLabel("学校"));
    layout->addWidget(universityEdit);

    layout->addWidget(saveButton);
    layout->addWidget(cancelButton);

    setLayout(layout);

    connect(saveButton,&QPushButton::clicked,this,&QDialog::accept);
    connect(cancelButton,&QPushButton::clicked,this,&QDialog::reject);
}
QString DetailDialog::updatedStudentId() const {
    return idEdit->text();
}

QString DetailDialog::updatedStudentName() const {
    return nameEdit->text();
}

QString DetailDialog::updatedStudentSex() const {
    return sexCombo->currentText();
}

double DetailDialog::updatedStudentHeight() const {
    return heightEdit->text().toDouble();
}

QString DetailDialog::updatedStudentCollege() const {
    return collegeEdit->text();
}
