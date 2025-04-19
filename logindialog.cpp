#include "logindialog.h"

#include<QDialog>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("学生管理系统");
    resize(300,150);
    initWidget();
}

void LoginDialog::initWidget()
{
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("登录");
    cancelButton = new QPushButton("取消");

    connect(loginButton,&QPushButton::clicked,this,&LoginDialog::handleLogin);
    connect(cancelButton,&QPushButton::clicked,this,&LoginDialog::rejected);

    QFormLayout *formlayout = new QFormLayout;
    formlayout->addRow("用户名:",usernameEdit);
    formlayout->addRow("密码:",passwordEdit);

    QHBoxLayout *btnBox = new QHBoxLayout;
    btnBox->addStretch();
    btnBox->addWidget(loginButton);
    btnBox->addWidget(cancelButton);

    QVBoxLayout *mainBox = new QVBoxLayout;
    mainBox->addLayout(formlayout);
    mainBox->addLayout(btnBox);

    setLayout(mainBox);
}

void LoginDialog::handleLogin()
{
    QString user = usernameEdit->text();
    QString password = passwordEdit->text();

    if(user == "admin" && password == "123456"){
        accept();
    }
    else{
        QMessageBox::warning(this,"登录失败","用户名或者密码错误");
    }
}
