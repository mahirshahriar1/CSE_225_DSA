#include <iostream>
#include "src/quetype.cpp"
using namespace std;

int main()
{
    QueType<int> coins;
    QueType<int> counts;

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        coins.Enqueue(arr[i]);
        counts.Enqueue(1);
    }

    int target;
    cin>>target;

    int money=0,cnt=0;
    while(money!=target){
        coins.Dequeue(money);
        counts.Dequeue(cnt);

        for(int i=0;i<n;i++){
            coins.Enqueue(arr[i]+money);
            counts.Enqueue(cnt+1);
        }
    }

    cout<<cnt<<endl;

    return 0;
}
