#include <iostream>
#include "src/graphtype.cpp"
using namespace std;

template <class T>
void printAdj(GraphType<T> &graph, T item){
    QueType<T> vertexQ;
    graph.GetToVertices(item,vertexQ);
    while (!vertexQ.IsEmpty())
    {
        vertexQ.Dequeue(item);
        cout<<item<<' ';
    }
    cout<<endl;
}

int main()
{
    GraphType<int> graph;

    graph.AddVertex(5);
    graph.AddVertex(6);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddVertex(2);
    graph.AddVertex(8);
    graph.AddVertex(1);

    //unordered graph
    graph.AddEdge(5,6,100); graph.AddEdge(6,5,100);
    graph.AddEdge(5,8,100); graph.AddEdge(8,5,100);
    graph.AddEdge(6,2,100); graph.AddEdge(2,6,100);
    graph.AddEdge(6,1,100); graph.AddEdge(1,6,100);
    graph.AddEdge(3,8,100); graph.AddEdge(8,3,100);
    graph.AddEdge(3,1,100); graph.AddEdge(1,3,100);
    graph.AddEdge(3,4,100); graph.AddEdge(4,3,100);
    graph.AddEdge(4,2,100); graph.AddEdge(2,4,100);
    graph.AddEdge(4,1,100); graph.AddEdge(1,4,100);
    cout<<"Adjacent vertices of vertex 3 : ";
    printAdj(graph,3);
    cout<<"Shortest path between from between 5 to 1 : ";
    graph.custom_BFS(5,1);


    return 0;
}
