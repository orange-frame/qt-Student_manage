#ifndef STUDENT_H
#define STUDENT_H
#include<QString>

class Student{
public:
    QString s_id;  //学生学号
    QString name;  //姓名
    QString sex;    //性别
    double height;  //身高
    QString college;    //所属学院
    QString university;
    QString avatarPath;

    Student()=default;
    Student(const QString &id,const QString &name,const QString &sex,const double &height,const QString college,QString university,QString avatarPath)
        :s_id(id),name(name),sex(sex),height(height),college(college),university(university),avatarPath(avatarPath)
    {}
};
#endif // STUDENT_H
