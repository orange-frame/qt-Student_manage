#include "mainwindow.h"
#include "logindialog.h"

#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog login;
    QFile file(":/style.css");
    if(file.open(QFile::ReadOnly)){
        a.setStyleSheet(file.readAll());
        file.close();
    }
    if(login.exec() == QDialog::Accepted){
        MainWindow w;
        w.show();
        return a.exec();
    }
    else{
        return 0;
    }
}
