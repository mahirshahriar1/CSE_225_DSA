#include <bits/stdc++.h>
#include "src/UnsortedType.cpp"
using namespace std;


template <class T>
void print(UnsortedType<T> &ulist){
    ulist.ResetList();
    int n=ulist.LengthIs();
    T item;
    for(int i=0;i<n;i++){
        ulist.GetNextItem(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

template <class T>
void retrieve(UnsortedType<T> &ulist, T item){
    bool found;

    ulist.RetrieveItem(item,found);
    if(found){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
}

template <class T>
void fullcheck(UnsortedType<T>& ulist){

    bool full=ulist.IsFull();
    if(full) cout<<"List is full"<<endl;
    else     cout<<"List is not full"<<endl;

}

int main()
{
    UnsortedType<int> ulist;
    //inserting elements
    ulist.InsertItem(5);
    ulist.InsertItem(7);
    ulist.InsertItem(6);
    ulist.InsertItem(9);
    // printing using given print function
    ulist.Print();

    cout<<ulist.LengthIs()<<endl;

    ulist.InsertItem(1);
    print(ulist); // printing using user defined function

    //retrieving items using user defined function
    retrieve(ulist,4);
    retrieve(ulist,5);
    retrieve(ulist,9);
    retrieve(ulist,10);

    // checking if the list is full using user defined function
    fullcheck(ulist);

    ulist.DeleteItem(5);

    fullcheck(ulist);

    ulist.DeleteItem(1);
    print(ulist);

    ulist.DeleteItem(6);
    print(ulist);

    // making the list empty
    ulist.MakeEmpty();

    return 0;
}
