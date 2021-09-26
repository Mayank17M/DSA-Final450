/**
 * Detect cycle in an undirected graph using DFS
 * References: 
 *  https://www.youtube.com/watch?v=Y9NFqI6Pzd4&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9
 */ 

#include <bits/stdc++.h>
using namespace std;
 
bool checkCycleDFS(int key, int parent, vector<bool> &visited, vector<int> adj[]){
    visited[key]=true;
    for(auto i: adj[key]){
        if(!visited[i]){
            if(checkCycleDFS(i, key, visited, adj)) return true;
        } else if(i != parent) return true;
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,false);
    for(int i=0; i<V; i++){
        if(!visited[i]){
            if(checkCycleDFS(i, -1, visited, adj)) return true;
        }
    }
    return false;
}
 
// Driver code
int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isCycle(V, adj);
    ans? cout<<"Cycle Detected": cout<<"Cycle Not Detected";
    return 0;
}