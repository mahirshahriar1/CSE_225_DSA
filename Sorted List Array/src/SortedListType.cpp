#include "SortedListType.h"
#include <iostream>
using namespace std;
template <class ItemType>
SortedListType<ItemType>::SortedListType()
{
//ctor
    length = 0;
    currentPos = -1;
}
template <class ItemType>
SortedListType<ItemType>::~SortedListType()
{
//dtor
}
template <class ItemType>
void SortedListType<ItemType>::MakeEmpty()
{
    length = 0;
    currentPos = -1;
}
template <class ItemType>
bool SortedListType<ItemType>::IsFull()
{
    return (length==MAX_ITEMS);
}
template <class ItemType>
int SortedListType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void SortedListType<ItemType>::ResetList()
{
    currentPos = -1;
}
template <class ItemType>
void
SortedListType<ItemType>::GetNextItem(ItemType&
                                      item)
{
    currentPos++;
    item = info[currentPos];
}
template <class ItemType>
void
SortedListType<ItemType>::InsertItem(ItemType
                                     item)
{
    int location, index;
    if (length>=MAX_ITEMS)
        return;
    location = 0;
    while (location<length &&
            info[location]<item)
    {
        location++;
    }
    if (info[location]==item)
        return;
    for (index=length; index>location; index--)
    {
        info[index] = info[index-1];
    }
    info[location] = item;
    length++;
    return;
}
template <class ItemType>
void
SortedListType<ItemType>::DeleteItem(ItemType
                                     item)
{
    int location = 0, index;
    while (location<length &&
            info[location]<item)
    {
        location++;
    }
    if (info[location]==item)
    {
        for (index=location; index<length-1;
                index++)
        {
            info[index] = info[index+1];
        }
        length--;
    }
}
template <class ItemType>
void
SortedListType<ItemType>::RetrieveItem(ItemType&
                                       item, bool& found)
{
    int mid, first = 0, last = length-1;
    while (first<=last)
    {
        mid = (first+last)/2;
        if (info[mid]==item)
        {
            found = true;
            return;
        }
        if (info[mid]<item)
            first = mid + 1;
        else
            last = mid - 1;
    }
    found = false;
}
template <class ItemType>
void SortedListType<ItemType>::Print()
{
    cout << "The items are: ";
    for (int i=0; i<length; i++)
    {
        cout << info[i] << "  ";
    }
    cout << endl;
}
