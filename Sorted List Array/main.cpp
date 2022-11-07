#include <bits/stdc++.h>
#include "src/sortedlisttype.cpp"
using namespace std;

template <class T>
void printlist(SortedListType<T>& li){
    int n=li.LengthIs();
    li.ResetList();
    T item;
    for(int i=0;i<n;i++){
        li.GetNextItem(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

template<class T>
void retrieve(SortedListType <T> & li,T item){
    bool found;
    li.RetrieveItem(item,found);
    if(found){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
}

template<class T>
void isfull(SortedListType<T>& li){
    if(li.IsFull()){
        cout<<"List is full"<<endl;
    }else{
        cout<<"List is not full"<<endl;
    }
}


int main()
{
    SortedListType <int> obj1;
    cout<<obj1.LengthIs()<<endl;
    obj1.InsertItem(5);
    obj1.InsertItem(7);
    obj1.InsertItem(4);
    obj1.InsertItem(2);retrieve(obj1,6);
    obj1.InsertItem(1);

    obj1.Print();
    retrieve(obj1,6);
    retrieve(obj1,5);
    isfull(obj1);

    obj1.DeleteItem(1);
    printlist(obj1);
    isfull(obj1);

    return 0;
}
