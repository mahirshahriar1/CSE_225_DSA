#include <iostream>
#include "src/quetype.cpp"
using namespace std;

int main()
{
    QueType<string> tickets;
    tickets.Enqueue("Tck1");
    tickets.Enqueue("Tck2");
    tickets.Enqueue("Tck3");
    tickets.Enqueue("Tck4");
    tickets.Enqueue("Tck5");

    QueType<string> people;
    people.Enqueue("Any");
    people.Enqueue("Kris");
    people.Enqueue("Boby");
    people.Enqueue("Helena");

    QueType<int> id;
    id.Enqueue(222);
    id.Enqueue(173);
    id.Enqueue(152);
    id.Enqueue(221);

    while(!people.IsEmpty()){
        string p,t;
        int i;
        people.Dequeue(p);
        tickets.Dequeue(t);
        id.Dequeue(i);
        cout<<p<<' '<<i<<' '<<t<<endl;
    }

    return 0;
}
