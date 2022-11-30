#include <bits/stdc++.h>
#include "stacktype.cpp"

using namespace std;

bool isNum(char x){
    return (x>='0' and x<='9');
}

bool isOperator(char x){
    return (x=='+'||x=='-'||x=='*'||x=='/');
}

int precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

int main(){

    string equation;
    getline(cin,equation);

    string postfix="",temp="";
    bool unbalanced=false;

    StackType<char> operands;

    for(auto x:equation){
        if(isNum(x)){
            temp+=x;
        }else{

            if(temp!=""){
                postfix+=temp+'.';
                temp="";
            }

            if(isOperator(x)){
                while(!operands.IsEmpty() and precedence(x)<=precedence(operands.Top())){
                    postfix += operands.Top();
                    operands.Pop();
                }
                operands.Push(x);
            }

            else if(x=='('){
                operands.Push(x);
            }

            else if(x==')'){
                bool found=false;

                while(!operands.IsEmpty() and operands.Top()!='('){
                    postfix+=operands.Top();
                    operands.Pop();

                    if(operands.Top() == '('){
                        found = true;
                    }
                }
                if(!found){
                    unbalanced=true;
                    break;
                }else{
                    operands.Pop();
                }
            }

            else{
                continue;
            }
        }
    }

    if(unbalanced){
        cout<<"Invalid Expression"<<endl;
        return 0;
    }
    while(!operands.IsEmpty()){
        postfix+=operands.Top();
        operands.Pop();
    }

    cout<<postfix<<endl;

    return 0;
}
