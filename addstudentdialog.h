#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H

#include <QDialog>
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QFormLayout>
#include<QString>

class AddStudentDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddStudentDialog(const QString &defaultName,QWidget *parent = nullptr);

    QString studentId() const;
    QString studentName() const;
    QString studentSex() const;
    double studentHeight() const;
    QString studentCollege() const;
private:
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QComboBox *sexCombo;
    QLineEdit *heightEdit;
    QLineEdit *collegeEdit;
    QPushButton *addButton;
    QPushButton *cancelButton;
};

#endif // ADDSTUDENTDIALOG_H
