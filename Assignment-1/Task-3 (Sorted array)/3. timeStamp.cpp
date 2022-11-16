#include "timeStamp.h"
#include <bits/stdc++.h>
using namespace std;
timeStamp::timeStamp()
{

}

timeStamp::timeStamp(int h,int m,int s)
{
    this->h=h;
    this->m=m;
    this->s=s;
}

bool timeStamp::operator!=(timeStamp obj){
    if(this->h!=obj.h||this->m!=obj.m||this->s!=obj.s){
        return true;
    }
    return false;
}
bool timeStamp::operator==(timeStamp obj){
    if(this->h==obj.h&&this->m==obj.m&&this->s==obj.s){
        return true;
    }
    return false;
}
bool timeStamp::operator<(timeStamp obj)
{
    if(this->h<obj.h)    
        return true;    

    else if(this->h==obj.h){
        if(this->m<obj.m)
            return true;
        else if(this->m==obj.m)        
            return(this->s<obj.s);        
        else
            return false;
    }

    else //this-h>obj.h
        return false;
}

ostream& operator<<(ostream& mycout,const timeStamp& obj)
{
    mycout << setfill('0') << setw(2);
    mycout<<obj.h<<":";
    mycout << setfill('0') << setw(2);
    mycout<<obj.m<<":";
    mycout << setfill('0') << setw(2);
    mycout<<obj.s;
    return mycout;
}
