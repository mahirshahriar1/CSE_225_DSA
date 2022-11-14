#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include<bits/stdc++.h>
using namespace std;
class studentInfo
{
    public:
        studentInfo();
        studentInfo(int);
        studentInfo(int,string,double);
        bool operator==(studentInfo s);
        bool operator<(studentInfo s);
        bool operator>(studentInfo s);
        int  getID();
        friend ostream& operator<<(ostream& mycout,const studentInfo& s);

    private:
        int id;
        string name;
        double cgpa;
};

#endif // STUDENTINFO_H
