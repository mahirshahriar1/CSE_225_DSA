#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H
#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = 100;
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

#endif // UNSORTEDTYPE_H
