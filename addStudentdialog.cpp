#include "addStudentdialog.h""
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>

AddStudentDialog::AddStudentDialog(const QString &defaultName, QWidget *parent) : QDialog(parent) {
    setWindowTitle("添加学生");

    idEdit = new QLineEdit(this);
    nameEdit = new QLineEdit(this);
    sexCombo = new QComboBox(this);
    sexCombo->addItem("男");
    sexCombo->addItem("女");
    heightEdit = new QLineEdit(this);
    collegeEdit = new QLineEdit(this);

    collegeEdit->setText(defaultName);
    addButton = new QPushButton("添加", this);
    cancelButton = new QPushButton("取消", this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("学号", idEdit);
    formLayout->addRow("姓名", nameEdit);
    formLayout->addRow("性别", sexCombo);
    formLayout->addRow("身高", heightEdit);
    formLayout->addRow("学院", collegeEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(addButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);

    connect(addButton, &QPushButton::clicked, this, &AddStudentDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &AddStudentDialog::reject);
}

QString AddStudentDialog::studentId() const {
    return idEdit->text();
}

QString AddStudentDialog::studentName() const {
    return nameEdit->text();
}

QString AddStudentDialog::studentSex() const {
    return sexCombo->currentText();
}

double AddStudentDialog::studentHeight() const {
    return heightEdit->text().toDouble();
}

QString AddStudentDialog::studentCollege() const {
    return collegeEdit->text();
}
