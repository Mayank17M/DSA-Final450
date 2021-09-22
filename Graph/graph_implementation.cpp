/** 
 * Directed Graph Implementation C++;
 */

#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph {
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N){
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges){
            // insert at the end
            adjList[edge.src].push_back(edge.dest);
 
            // uncomment the following code for undirected graph
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int N) {
    for (int i = 0; i < N; i++) {
        // print the current vertex number
        cout << i << " ——> ";
 
        // print all neighboring vertices of a vertex `i`
        for (int v: graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
 
// Graph Implementation using STL
int main() {

    // total number of nodes in the graph
    int N = 6;
    vector<Edge> edges ={
        { 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 3, 2 }, { 4, 5 }, { 5, 4 }
    };
  
    // construct graph
    Graph graph(edges, N);
 
    // print adjacency list representation of a graph
    printGraph(graph, N);
 
    return 0;
}


