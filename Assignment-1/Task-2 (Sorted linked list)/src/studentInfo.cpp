#include "studentInfo.h"


studentInfo::studentInfo()
{

}

studentInfo::studentInfo(int id)
{
    this->id=id;
}

studentInfo::studentInfo(int id,string name,double cgpa)
{
    this->id=id;
    this->name=name;
    this->cgpa=cgpa;
}

int studentInfo::getID(){
    return id;
}

bool studentInfo::operator==(studentInfo s)
{
    if(this->id==s.id)
        return true;
    return false;
}
bool studentInfo::operator<(studentInfo s)
{
    if(this->id<s.id)
        return true;
    return false;
}
bool studentInfo::operator>(studentInfo s)
{
    if(this->id>s.id)
        return true;
    return false;
}

ostream& operator<<(ostream& mycout,const studentInfo& s)
{
    mycout<<s.id<<","<<s.name<<","<<s.cgpa;
    return mycout;
}
