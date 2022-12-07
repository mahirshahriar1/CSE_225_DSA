#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int x){
    if(x/10==0){
        return x;
    }
    return x%10+sumOfDigits(x/10);
}

int main(){
    int n;
    while(cin>>n){
        cout<<"Sum of digits of "<<n<<" is : "<<sumOfDigits(n)<<endl;
    }
    return 0;
}
