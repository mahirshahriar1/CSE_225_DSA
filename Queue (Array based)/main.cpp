#include <iostream>
#include "src/quetype.cpp"
using namespace std;


template <class T>
void checkEmpty(QueType <T> q){
    if(q.IsEmpty()){
        cout<<"Queue is Empty"<<endl;
    }else{
        cout<<"Queue is not Empty"<<endl;
    }

}

template <class T>
void checkFull(QueType <T> q){
    if(q.IsFull()){
        cout<<"Queue is full"<<endl;
    }else{
        cout<<"Queue is not full"<<endl;
    }
}

template <class T>
void print(QueType <T> q){
    T item;
    while(!q.IsEmpty()){
        q.Dequeue(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

template <class T>
void qins(QueType <T> &q,T item){

    if(q.IsFull()){
        cout<<"Queue Overflow"<<endl;
    }else{
        q.Enqueue(item);
    }
}

template <class T>
void qdel(QueType <T> &q,T &item){

    if(q.IsEmpty()){
        cout<<"Queue Underflow"<<endl;
    }else{
        q.Dequeue(item);
    }
}


int main()
{
    QueType <int> que(5);

    checkEmpty(que);
    qins(que,5);
    qins(que,7);
    qins(que,4);
    qins(que,2);


    checkEmpty(que);
    checkFull(que);
    qins(que,6);

    print(que);
    checkFull(que);

    qins(que,8);

    int item;
    qdel(que,item);
    qdel(que,item);

    print(que);

    qdel(que,item);
    qdel(que,item);
    qdel(que,item);

    checkEmpty(que);

    qdel(que,item);


    /*Take an integer n from the user as input and use a queue to print
    binary values of each integer from 1 to n. Here is how it can be
    done.
        o Create an empty queue
        o Enqueue the first binary number “1” to the queue.
        o Now run a loop for generating and printing n binary
        numbers.
        ▪ Dequeue and print the value.
        ▪ Append “0” at the dequeued value and enqueue it.
        ▪ Append “1” at the dequeued value and enqueue it.*/

    cout<<"Enter a number: ";
    int n;
    cin>>n;
//    QueType<string> q;
//    string temp="1";
//    while(n--){
//        qdel(q,temp);
//        cout<<temp<<endl;
//
//        string x=temp+"0";
//        string y=temp+"1";
//
//        q.Enqueue(x);
//        q.Enqueue(y);
//    }

    QueType<int> q;
    int temp=1;
    qins(q,temp);
    while(n--){
        qdel(q,temp);
        cout<<temp<<endl;

        int x=temp;
        x=x*10;
        int y=temp;
        y=y*10;
        y++;

        qins(q,x);
        qins(q,y);
    }



    return 0;
}
