#include <iostream>
#include "UnsortedType.cpp"
using namespace std;

template <class T>
void print(UnsortedType<T> &obj)
{
    obj.ResetList();
    int n=obj.LengthIs();
    T item;
    while(n--)
    {
        obj.GetNextItem(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

template <class T>
void retrieve(UnsortedType <int> & obj,T item)
{
    bool b;
    obj.RetrieveItem(item,b);
    if(b)
    {
        cout<<"Item is found"<<endl;
    }
    else
    {
        cout<<"Item is not found"<<endl;
    }
}

template <class T>
void checkfull(UnsortedType <T> &obj)
{
    bool b=obj.IsFull();
    if(b)
    {
        cout<<"List is full"<<endl;
    }
    else
    {
        cout<<"List is not full"<<endl;
    }
}


int main()
{
    UnsortedType <int> obj;
    obj.InsertItemAtEnd(5);
    obj.InsertItemAtEnd(7);
    obj.InsertItemAtEnd(6);
    obj.InsertItemAtEnd(9);

    obj.PrintList();
                cout<<endl;
    obj.InsertItemAtEnd(1);

    print(obj);

    retrieve(obj,10);

    checkfull(obj);

    obj.DeleteItem(5);
    checkfull(obj);
    obj.DeleteItem(1);

    print(obj);etrieve(obj,4);
    retrieve(obj,5);
    retrieve(obj,9);
    retrieve(obj,10);

    checkfull(obj);

    obj.DeleteItem(5);
    checkfull(obj);
    obj.DeleteItem(1);

    print(obj);

    return 0;
}
