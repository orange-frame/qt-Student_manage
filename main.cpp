#include "mainwindow.h"
#include "logindialog.h"
#include "treepanel.h"
#include"tablepanel.h"

#include <QApplication>
#include<QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog login;

    QFile file(":/qss/style.css");
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

        MainWindow w;
        w.show();
    return a.exec();
}
