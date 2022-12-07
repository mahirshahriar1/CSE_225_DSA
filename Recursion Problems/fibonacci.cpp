#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int main(){
    int n;
    while(cin>>n){
        cout<<n<<"th element of Fibonacci Sequence is : "<<fib(n)<<endl;
    }
    return 0;
}
