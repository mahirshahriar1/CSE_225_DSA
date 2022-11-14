#include<bits/stdc++.h>
using namespace std;
#include "UnsortedType.h"

template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    if(length == 0){
        //cout << "List is empty."<< endl;
    }
    else if(length > 0)
    {
        length = 0;
        //cout <<"All items deleted."<< endl;
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
    while (item!=info[i] && i<length)
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

