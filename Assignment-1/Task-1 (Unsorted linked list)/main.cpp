#include <iostream>
#include "src/UnsortedType.cpp"
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

int main()
{
    UnsortedType <int> obj1,obj2,ans;
    int l1,l2;

    cin>>l1;
    for(int i=0; i<l1; i++)
    {
        int temp;
        cin>>temp;
        obj1.InsertItemAtEnd(temp);
    }

    cin>>l2;
    for(int i=0; i<l2; i++)
    {
        int temp;
        cin>>temp;
        obj2.InsertItemAtEnd(temp);
    }

    obj1.ResetList();
    obj2.ResetList();
    int item1,item2;
    obj1.GetNextItem(item1);
    obj2.GetNextItem(item2);

    while(l1 and l2)
    {
        if(item1<item2)
        {
            ans.InsertItemAtEnd(item1);
            l1--;
            if(l1==0)
                break;
            obj1.GetNextItem(item1);

        }
        else if(item1>item2)
        {

            ans.InsertItemAtEnd(item2);
            l2--;
            if(l2==0)
                break;
            obj2.GetNextItem(item2);
        }
        else
        {
            //cout<<item1<<' '<<item2<<endl;
            //item1==item2
            ans.InsertItemAtEnd(item1);
            ans.InsertItemAtEnd(item2);

            l1--;
            l2--;
            if(!l1||!l2)
                break;
            obj1.GetNextItem(item1);
            obj2.GetNextItem(item2);
        }

    }

    while(l1)
    {
        ans.InsertItemAtEnd(item1);
        l1--;
        if(!l1)
            break;
        obj1.GetNextItem(item1);
    }
    while(l2)
    {
        ans.InsertItemAtEnd(item2);
        l2--;
        if(!l2)
            break;
        obj2.GetNextItem(item2);
    }

    print(ans); //prints the linked list


    return 0;
}
