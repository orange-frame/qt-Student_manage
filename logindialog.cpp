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

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("用户名:", usernameEdit);
    formLayout->addRow("密码:", passwordEdit);

    // 中间包一层 QWidget + QHBoxLayout → 居中 formLayout
    QWidget *formContainer = new QWidget(this);
    QHBoxLayout *formHCenter = new QHBoxLayout(formContainer);
    formHCenter->addStretch();
    formHCenter->addLayout(formLayout);
    formHCenter->addStretch();
    formHCenter->setContentsMargins(0, 0, 0, 0);

    // 按钮区
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(cancelButton);

    // 主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addWidget(formContainer);  // 让 form 在中间显示
    mainLayout->addSpacing(10);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    mainLayout->setContentsMargins(30, 30, 30, 30);
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
