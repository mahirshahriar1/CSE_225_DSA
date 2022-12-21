#include <iostream>
#include "src/graphtype.cpp"
using namespace std;

template <class T>
void edgePrint(GraphType<T>& graph, T a, T b){
    if(graph.FoundEdge(a,b)){
        cout<<"There is an edge."<<endl;
    }else{
        cout<<"There is no edge."<<endl;
    }
}

int main()
{
    GraphType<char> graph;

    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddVertex('D');
    graph.AddVertex('E');
    graph.AddVertex('F');
    graph.AddVertex('G');
    graph.AddVertex('H');

    graph.AddEdge('A','B',1);
    graph.AddEdge('B','A',1);
    graph.AddEdge('A','C',1);
    graph.AddEdge('A','D',1);
    graph.AddEdge('D','A',1);
    graph.AddEdge('D','G',1);
    graph.AddEdge('D','E',1);
    graph.AddEdge('G','F',1);
    graph.AddEdge('F','H',1);
    graph.AddEdge('H','E',1);

    cout<<graph.OutDegree('B')<<endl;
    cout<<graph.OutDegree('D')<<endl;
    edgePrint(graph,'A','D');
    edgePrint(graph,'B','D');

    graph.DepthFirstSearch('B','E');
    graph.DepthFirstSearch('E','B');

    graph.BFS_shortest_distance('B','E');
    graph.BFS_shortest_distance('D','C');
    graph.BFS_shortest_distance('H','D');
    graph.BFS_shortest_distance('B','H');


    return 0;
}
