#include <iostream>
#include "SortedListType.cpp"
#include "timeStamp.h"
using namespace std;

template <class T>
void printSorted(SortedListType<T> &obj)
{
    obj.ResetList();
    int n=obj.LengthIs();
    T item;
    while(n--)
    {
        obj.GetNextItem(item);
        cout<<item<<endl;
    }
    cout<<endl;
}

//template <class T>
//void printUnsorted(UnsortedType<T> &obj)
//{
//    obj.ResetList();
//    int n=obj.LengthIs();
//    T item;
//    while(n--)
//    {
//        obj.GetNextItem(item);
//        cout<<item<<endl;
//    }
//    cout<<endl;
//}

int main()
{
    /*
        Solved this problem using Sorted List.
        timeStamp class will work for Unsorted List as well.
    */
    timeStamp ts1(15, 34, 23);
    timeStamp ts2(13, 13, 02);
    timeStamp ts3(12, 45, 43);
    timeStamp ts4(17, 36, 25);
    timeStamp ts5(20, 02, 52);

    SortedListType<timeStamp> list1;
    list1.InsertItem(ts1);
    list1.InsertItem(ts2);
    list1.InsertItem(ts3);
    list1.InsertItem(ts4);
    list1.InsertItem(ts5);

    printSorted(list1);

    cout<<"\nAfter deleting 12:45:43 ->\n"<<endl;
    list1.DeleteItem(timeStamp(12, 45,43));
    printSorted(list1);

    return 0;
}
