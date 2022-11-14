#include <iostream>
#include "src/sortedtype.cpp"
#include "studentInfo.h"
using namespace std;

//function to print the list
template <class T>
void print(SortedType<T> &obj){
    obj.ResetList();
    int n=obj.LengthIs();
    T item;
    while(n--){
        obj.GetNextItem(item);
        cout<<item<<endl;
    }
}

//function to print info of a given id
template <class T>
void print_specific(SortedType<T> &obj,int id){
    obj.ResetList();
    int n=obj.LengthIs();
    T item;
    while(n--){
        obj.GetNextItem(item);
        if(item.getID()==id){
            cout<<item<<endl;
            break;
        }
    }
}

//function to show retrieve items
template <class T>
void retrieve(SortedType<T> &obj,T item){
    bool b;
    obj.RetrieveItem(item,b);
    if(b){
        cout<<"Item is found"<<endl;
        print_specific(obj,item.getID());
    }else{
        cout<<"Item is not found"<<endl;
    }
}

int main()
{
    studentInfo st1(15234,"Jon", 2.6);
    studentInfo st2(13732 ,"Tyrion", 3.9);
    studentInfo st3(13569 ,"Sandor", 1.2);
    studentInfo st4(15467 ,"Ramsey", 3.1);
    studentInfo st5(16285 ,"Arya", 3.1);
    //cout<<s1<<endl;

    SortedType <studentInfo> list1;
    list1.InsertItem(st1);
     list1.InsertItem(st2);
      list1.InsertItem(st3);
       list1.InsertItem(st4);
        list1.InsertItem(st5);

   // print(list1);
   studentInfo del(15467);
   list1.DeleteItem(del);

   retrieve(list1,studentInfo (13569));
   cout<<endl;

   print(list1);

    return 0;
}
