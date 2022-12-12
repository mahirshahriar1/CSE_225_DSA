#include <bits/stdc++.h>
using namespace std;

void printDigit(int n){
    if(n/10==0){
        goto label;
        return;
    }
    printDigit(n/10);
    label:
    int x=n%10;
    switch(x){
        case 1: cout<<"One "; break;
        case 2: cout<<"Two "; break;
        case 3: cout<<"Three "; break;
        case 4: cout<<"Four "; break;
        case 5: cout<<"Five "; break;
        case 6: cout<<"Six "; break;
        case 7: cout<<"Seven "; break;
        case 8: cout<<"Eight "; break;
        case 9: cout<<"Nine "; break;
        case 0: cout<<"Zero "; break;
        default: break;
    }
}

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

double series(int n){
    if(n==1){
        return 1;
    }
    return 1.0/factorial(n)+series(n-1);
}


int main(){
    cout<<"Question 1-"<<endl;
    cout<<series(1)<<endl;
    cout<<series(2)<<endl;
    cout<<series(3)<<endl;
    cout<<series(4)<<endl;
    cout<<series(5)<<endl;

    int n;
    cout<<"\n\nQuestion 2-"<<endl;
    cout<<"Enter an integer: ";
    cin>>n;
    printDigit(n);
    cout<<endl;
//    printDigit(12345);
//    cout<<endl;

    return 0;
}

