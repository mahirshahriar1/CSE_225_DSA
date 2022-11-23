#include <iostream>
#include "stacktype.cpp"
using namespace std;

template <class T>
void checkEmpty(StackType<T> &obj){
    if(obj.IsEmpty()){
        cout<<"Stack is Empty"<<endl;
    }else{
        cout<<"Stack is not Empty"<<endl;
    }
}

template <class T>
void checkFull(StackType<T> &obj){
    if(obj.IsFull()){
        cout<<"Stack is full"<<endl;
    }else{
        cout<<"Stack is not full"<<endl;
    }
}

template <class T>
void printStack(StackType<T> obj){
    StackType<T> temp;
    while(!obj.IsEmpty()){
        T item=obj.Top();
        temp.Push(item);
        obj.Pop();
    }
    while(!temp.IsEmpty()){
        cout<<temp.Top()<<' ';
        temp.Pop();
    }
    cout<<endl;
}

void checkParenthesis(string &s){
    StackType<char> brack;
    bool flag=true;
    for(int j=0;j<s.size();j++){
        if(s[j]=='('||s[j]=='{'||s[j]=='['){
            brack.Push(s[j]);
        }else{
            if(s[j]==')'){
                if(brack.IsEmpty() || brack.Top()!='(' ){
                    flag=false;
                    break;
                }else{
                    brack.Pop();
                }
            }else if(s[j]=='}'){
                if(brack.IsEmpty() || brack.Top()!='{' ){
                    flag=false;
                    break;
                }else{
                    brack.Pop();
                }
            }else if(s[j]==']'){
                if(brack.IsEmpty() || brack.Top()!='[' ){
                    flag=false;
                    break;
                }else{
                    brack.Pop();
                }
            }
        }
    }

    if(brack.IsEmpty() and flag){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
    brack.Clear();
}

int main()
{
    StackType<int> stk;

    checkEmpty(stk);

    stk.Push(5);
    stk.Push(7);
    stk.Push(4);
    stk.Push(2);

    checkEmpty(stk);
    checkFull(stk);

    printStack(stk);

    stk.Push(3);

    printStack(stk);

    checkFull(stk);
    stk.Pop();
    stk.Pop();
    cout<<stk.Top()<<endl;

    stk.Clear();


    //Parenthesis Balance
    for(int i=0;i<4;i++){
        string s;
        cin>>s;
        checkParenthesis(s);
    }

    return 0;
}
