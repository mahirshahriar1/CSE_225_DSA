#include <bits/stdc++.h>
#include "UnsortedType.h"
using namespace std;
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    MakeEmpty();
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
// Add Item to the front
void UnsortedType<ItemType>::InsertItemAtBeg(ItemType
                                        item)
{
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}

template <class ItemType>
// Add Item to the back
void UnsortedType<ItemType>::InsertItemAtEnd(ItemType
                                        item)
{
    NodeType* ptr= listData;
    NodeType* prev= NULL;

    NodeType* loc= new NodeType;

    while(ptr!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }
    
    if(prev==NULL){
        loc->info = item;
        loc->next = listData;
        listData = loc;
    }else{
        loc->info = item;
        loc->next = NULL;
        prev->next=loc;
    }

    length++;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType
                                        item)
{
    // NodeType* location = listData;
    // NodeType* tempLocation;
    // bool found=false;
    // if (item == listData->info)
    // {
    //     listData = listData->next;
    //     found=true;
    // }
    // else
    // {
    //     while (location->next!=NULL&&(item!=(location->next)->info))
    //         location = location->next;            
        
    //     if(location->next==NULL){
    //         found=false;
    //     }
    //     else{ 
    //         found=true;
    //         location->next = location->next->next;
    //     }
    // }
    // if(found){
    //      delete location;
    //      length--;
    // }else{
    //     cout<<item<<" is not present in the list."<<endl;
    // }

    //-------------------------------------------//
    bool found=false;
    NodeType* location = listData;
    NodeType* prev=NULL;
    if (item == listData->info)
    {
        listData = listData->next;
        found=true;
    }
    else
    {
        while (location!=NULL&&item!=(location->info)){
            prev=location;
            location = location->next;
        }

        if(location==NULL){
            found=false;
        }
        else{ 
            found=true;
            prev->next = location->next;
        }
    }
    if(found){
         delete location;
         length--;
    }else{
        cout<<item<<" is not present in the list."<<endl;
    }
      
}

template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void
UnsortedType<ItemType>::RetrieveItem(ItemType&
                                     item, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while (moreToSearch && !found)
    {
        if (item == location->info)
            found = true;
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void
UnsortedType<ItemType>::GetNextItem(ItemType&
                                    item)
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}
template <class ItemType>
void UnsortedType<ItemType>::PrintList()
{
    NodeType* tempPtr = listData;
    while (tempPtr!=NULL)
    {
        cout << tempPtr->info << " ";
        tempPtr = tempPtr->next;
    }
    return;
}
