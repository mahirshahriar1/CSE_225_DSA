#include <iostream>
#include <vector>
#include "src/binarysearchtree.cpp"
using namespace std;

template<class T>
void retrieve(TreeType<T> &tree,T item){
    bool b;
    tree.RetrieveItem(item,b);
    if(b){
        cout<<"Item is found"<<endl;
    }else{
        cout<<"Item is not found"<<endl;
    }
}


void minHeight(TreeType<int>& tree,const vector<int> &v,int start,int end){

    if(start>end)
        return;

    int mid=(start+end)>>1;

    tree.InsertItem(v[mid]);

    minHeight(tree, v,start,mid-1);

    minHeight(tree, v,mid+1,end);
}


int main()
{
    TreeType<int> tree;
    tree.InsertItem(76);

    tree.InsertItem(52);
    tree.InsertItem(75);
    tree.InsertItem(93);
    tree.InsertItem(97);
    tree.InsertItem(105);
    tree.InsertItem(28);
    tree.InsertItem(13);
    tree.InsertItem(11);
    tree.InsertItem(9);
    tree.InsertItem(2);
    tree.InsertItem(10);
    tree.InsertItem(25);
    tree.InsertItem(19);
    tree.InsertItem(54);
    tree.InsertItem(16);
    tree.InsertItem(18);
    tree.InsertItem(95);

    vector<int> v;
    tree.ResetTree(IN_ORDER);
    bool finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,IN_ORDER,finish);
        v.push_back(val);
    }

//    for(auto x: v){
//        cout<<x<<endl;
//    }

    tree.MakeEmpty();
    int start=0,end=v.size()-1;
    minHeight(tree,v,start,end);


    tree.ResetTree(PRE_ORDER);
    finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,PRE_ORDER,finish);
        cout<<val<<' ';
    }
    cout<<endl;

    tree.DeleteItem(9);
    tree.DeleteItem(2);
    tree.DeleteItem(25);

//    tree.ResetTree(PRE_ORDER);
//    finish = 0;
//    while(!finish){
//        int val;
//        tree.GetNextItem(val,PRE_ORDER,finish);
//        cout<<val<<' ';
//    }
//    cout<<endl;

    retrieve(tree,25);
    retrieve(tree,11);


    return 0;
}
