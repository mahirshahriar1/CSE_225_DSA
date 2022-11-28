#ifndef SORTEDLISTTYPE_H
#define SORTEDLISTTYPE_H
const int MAX_ITEMS = 5;
template <class ItemType>
class SortedListType
{
public :
    SortedListType();
    ~SortedListType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void RetrieveItem(ItemType&,
                      bool&);
    void ResetList();
    void GetNextItem(ItemType&);
    void Print();
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};
#endif
