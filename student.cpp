#include<QString>

class Student{
public:
    QString s_id;  //学生学号
    QString name;  //姓名
    QString sex;    //性别
    double height;  //身高
    QString college;    //所属学院
    Student(const QString &id,const QString &name,const QString &sex,const double &height,const QString college)
        :s_id(id),name(name),sex(sex),height(height),college(college)
    {

    }
};
