#include <iostream>
#include <vector>
#include "src/binarysearchtree.cpp"
using namespace std;

void checkEmpty(bool b){
    if(b){
        cout<<"Tree is Empty"<<endl;
    }else{
        cout<<"Tree is not Empty"<<endl;
    }
}

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


void insertBest(TreeType<int>& tree,const vector<int> &v,int start,int end){
    /* Base Case */
    if(start>end)
        return;
   /*Get the middle element and insert it*/
    int mid=(start+end)>>1;

    tree.InsertItem(v[mid]);

    /* Recursively construct the left subtree
    and make it left child of root */
    insertBest(tree, v,start,mid-1);

    /* Recursively construct the right subtree
    and make it right child of root */
    insertBest(tree, v,mid+1,end);
}


int main()
{
    TreeType<int> tree;
    checkEmpty(tree.IsEmpty());
    //4  9  2  7  3  11  17  0  5  1
        tree.InsertItem(4);
        tree.InsertItem(9);
        tree.InsertItem(2);
        tree.InsertItem(7);
        tree.InsertItem(3);
        tree.InsertItem(11);
        tree.InsertItem(17);
        tree.InsertItem(0);
        tree.InsertItem(5);
        tree.InsertItem(1);
    checkEmpty(tree.IsEmpty());

    cout<<tree.LengthIs()<<endl;
    retrieve(tree,9);
    retrieve(tree,13);

    tree.ResetTree(IN_ORDER);
    bool finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,IN_ORDER,finish);
        cout<<val<<' ';
    }
    cout<<endl;

    tree.ResetTree(PRE_ORDER);
    finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,PRE_ORDER,finish);
        cout<<val<<' ';
    }
    cout<<endl;

    tree.ResetTree(POST_ORDER);
    finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,POST_ORDER,finish);
        cout<<val<<' ';
    }
    cout << endl;

//    tree.MakeEmpty();
//    checkEmpty(tree.IsEmpty());



/*Given a sequence of integers, determine the best ordering of
the integers to insert them into a binary search tree. The best
order is the one that will allow the binary search tree to have
the minimum height.
Hint: Sort the sequence (use the inorder traversal). The middle
element is the root. Insert it into an empty tree. Now in the
same way, recursively build the left subtree and then the right
subtree.
11  9  4  2  7  3  17  0  5  1
*/

    vector<int> v;
    tree.ResetTree(IN_ORDER);
    finish = 0;
    while(!finish){
        int val;
        tree.GetNextItem(val,IN_ORDER,finish);
        v.push_back(val);
    }

    TreeType<int> bestTree;
    int start=0,end=v.size()-1;
    insertBest(bestTree,v,start,end);


    bestTree.ResetTree(PRE_ORDER);
    finish = 0;
    while(!finish){
        int val;
        bestTree.GetNextItem(val,PRE_ORDER,finish);
        cout<<val<<' ';
    }
    cout<<endl;


    return 0;
}
