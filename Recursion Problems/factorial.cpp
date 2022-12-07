#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n<=0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    while(cin>>n){
        if(n<0){
            cout<<"Please Enter a Positive Number"<<endl;
            continue;
        }
        cout<<n<<"! is : "<<factorial(n)<<endl;
    }
    return 0;
}
