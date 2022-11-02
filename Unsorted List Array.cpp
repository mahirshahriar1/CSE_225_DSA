#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = 5;
template <class ItemType>
class UnsortedType
{
public :
    UnsortedType();
    ~UnsortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void RetrieveItem(ItemType&, bool&);
    void ResetList();
    void GetNextItem(ItemType&);
    void Print();
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};

//-----------------------------------------------------
//-----------------------------------------------------
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    if(length == 0)
        cout << "List is empty."<< endl;
    else if(length > 0)
    {
        length = 0;
        cout <<"All items deleted."<< endl;
    }
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    return (length==MAX_ITEMS);
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType
                                        item)
{
    if (length<MAX_ITEMS)
    {
        info[length] = item;
        length++;
    }
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType
                                        item)
{
    int i = 0;
    while (info[i]!=item && i<length)
        i++;
    if (i<length)
    {
        info[i] = info[length-1];
        length--;
    }
}
template <class ItemType>
void
UnsortedType<ItemType>::RetrieveItem(ItemType&
                                     item, bool& found)
{
    int i = 0;
    while (info[i]!=item && i<length)
        i++;
    if (i<length)
    {
        found = true;
        item = info[i];
    }
    else
        found = false;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = -1;
}
template <class ItemType>
void
UnsortedType<ItemType>::GetNextItem(ItemType&
                                    item)
{
    currentPos++;
    item = info[currentPos];
}
template <class ItemType>
void UnsortedType<ItemType>::Print()
{
    cout << "The items are: ";
    for (int i=0; i<length; i++)
    {
        cout << info[i] << " ";
    }
    cout << endl;
}


//-----------------------------------------------------
//-----------------------------------------------------
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
