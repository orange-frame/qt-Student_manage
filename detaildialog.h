#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>
#include <QWidget>
#include<QLineEdit>
#include<QComboBox>
#include<QLabel>
#include"student.h"

class DetailDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DetailDialog(const Student &student,QWidget *parent = nullptr);

    QString updatedStudentId() const;
    QString updatedStudentName() const;
    QString updatedStudentSex() const;
    double updatedStudentHeight() const;
    QString updatedStudentCollege() const;
private:
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QComboBox *sexCombo;
    QLineEdit *heightEdit;
    QLineEdit *collegeEdit;
    QLineEdit *universityEdit;
    QLabel *avatarLabel;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // DETAILDIALOG_H
