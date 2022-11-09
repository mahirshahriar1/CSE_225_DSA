#include <iostream>
#include "src/UnsortedType.cpp"

using namespace std;


template <class T>
void print( UnsortedType<T> & link){
    link.ResetList();
    int sz=link.LengthIs();

    int temp;
    while(sz--){
        link.GetNextItem(temp);
        cout<<temp<<' ';
    }
    cout<<endl;
}

template <class T>
void retrieve(UnsortedType<T>& link,  T item)
{
    bool found;
    link.ResetList();
    link.RetrieveItem(item,found);
    if(found){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
}

template <class T>
void fullcheck(UnsortedType<T> &link){
    bool full=link.IsFull();
    if(full){
        cout<<"List is full"<<endl;
    }else{
        cout<<"List is not full"<<endl;
    }
}

int main()
{
    UnsortedType<int> link;
    link.InsertItemAtEnd(5);
    link.InsertItemAtEnd(7);
    link.InsertItemAtEnd(6);
    link.InsertItemAtEnd(9);

    link.PrintList();
    cout<<endl;

    link.InsertItemAtEnd(1);

    print(link);

    retrieve(link,4);
    retrieve(link,5);
    retrieve(link,9);
    retrieve(link,10);

    link.DeleteItem(5);

    fullcheck(link);

    link.DeleteItem(1);

    print(link);

    return 0;
}
