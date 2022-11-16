#include <iostream>
#include "SortedType.cpp"

using namespace std;

template <class T>
void print(SortedType <T>& obj){
    obj.ResetList();
    int n=obj.LengthIs();

    T item;
    while(n--){
        obj.GetNextItem(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

template <class T>
void retrieve(SortedType<T> &obj,T item){
    bool b;
    obj.RetrieveItem(item,b);
    if(b){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
}


template <class T>
void isFull(SortedType<T> &obj){
    bool b;
    b=obj.IsFull();

    if(b){
        cout<<"List is full"<<endl;
    }else{
        cout<<"List is not full"<<endl;
    }

}

int main()
{
    SortedType <int> obj;

    cout<<obj.LengthIs()<<endl;

    obj.InsertItem(5);
    obj.InsertItem(4);
    obj.InsertItem(7);
    obj.InsertItem(2);
    obj.InsertItem(1);
    print(obj);

    retrieve(obj,6);
    retrieve(obj,5);

    isFull(obj);

    obj.DeleteItem(1);
    print(obj);

    isFull(obj);

    return 0;
}
