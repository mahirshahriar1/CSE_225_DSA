#include <bits/stdc++.h>
using namespace std;

int findMin(int a[], int size){
    if(size==1){
        return a[size-1];
    }
    return min(a[size-1],findMin(a,size-1));
}

int main(){
    int n;
    while(cin>>n){
        int arr[n];
        for(auto& x: arr)
            cin>>x;
        cout<<"Minimum element in the array is : "<<findMin(arr,n)<<endl;
    }

    return 0;
}

