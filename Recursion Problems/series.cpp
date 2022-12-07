#include <bits/stdc++.h>
using namespace std;

double series(int n){
    if(n==0){
        return 1;
    }
    return  1.0/pow(2,n)+series(n-1);
}

int main(){
    int n;
    while(cin>>n){
        cout<<"Sum of the series is : "<<series(n)<<endl;
    }
    return 0;
}

