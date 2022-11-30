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

    double evaluate(char x, double a, double b)
    {
        if     (x == '+') return a + b;    
        else if(x == '-') return a - b;
        else if(x == '*') return a * b;
        else if(x == '/') return a / b;       
    }

    void solve(string equation){
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

                        if(!operands.IsEmpty() and operands.Top() == '('){                                         
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
            cout<<"Invalid Expression."<<endl;
            return;
        }
        
        if(temp != ""){
            postfix += temp;
        }

        while(!operands.IsEmpty()){
            postfix+=operands.Top();
            operands.Pop();
        }

        double ans=0;
        StackType<double> values;
        int ind=0;  

        while(ind<postfix.length()){

            if(isNum(postfix[ind])){
                string temp="";
                while(isNum(postfix[ind])){
                    temp+=postfix[ind++];
                }
                int num=stoi(temp);
                values.Push(num);
            }

            else if(isOperator(postfix[ind])){

                if(values.IsEmpty()){              
                    unbalanced=true;
                    break;
                }

                double a=values.Top();
                values.Pop();
                
                if(values.IsEmpty()){                 
                    unbalanced=true;
                    break;
                }

                double b=values.Top();
                values.Pop();
                //cout<<b<<' '<<postfix[ind]<<' '<<a<<endl;  
                
                double c=evaluate(postfix[ind],b,a);
                values.Push(c);
                ind++;
            
            }
            
            else{
                ind++;
            }
        }
        
        if(unbalanced or values.IsEmpty()){
            cout<<"Invalid Expression."<<endl;
        }else{
            cout<<values.Top()<<endl;
        }

    }

    int main(){
        #ifndef ONLINE_JUDGE  
            freopen("input.txt", "r", stdin); 
            freopen("output.txt", "w",stdout);
        #endif
        
        string line;
        while(getline(cin,line)){
            solve(line);
        }    

        return 0;
    }
