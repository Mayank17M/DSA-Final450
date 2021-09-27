/**
 * Detect cycle in a directed graph using DFS
 * References: 
 *  https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13
 */ 

#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<bool> &visited, vector<bool> &dfsvisit, vector<int> adj[]){
    visited[node]= true;
    dfsvisit[node]= true;
    for(auto i: adj[node]){
        if(!visited[i]){
            if(checkCycle(i, visited, dfsvisit, adj)) return true;
        } else if(dfsvisit[i]) return true;
    }
    dfsvisit[node] = false;
    return false;
}


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    // code here
    vector<bool> visited(V, false);
    vector<bool> dfsvisit(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(i, visited, dfsvisit, adj)) return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bool ans = isCyclic(V, adj);
    ans? cout<<"Cycle Detected": cout<<"Cycle Not Detected";
    return 0;
}