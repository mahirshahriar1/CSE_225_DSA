#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include<bits/stdc++.h>
using namespace std;

class timeStamp
{
    public:
        timeStamp();
        timeStamp(int,int,int);
        friend ostream& operator<<(ostream& mycout,const timeStamp& obj);
        bool operator!=(timeStamp obj);

    private:
        int h;
        int m;
        int s;
};

#endif // TIMESTAMP_H
