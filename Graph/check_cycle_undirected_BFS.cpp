/**
 * Detect cycle in an undirected graph
 * References: 
 *  https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8
 */ 

#include <bits/stdc++.h>
using namespace std;
 
bool checkCycle(int src, vector<bool> &visited, vector<int> adj[]){
    queue<pair<int, int> > q;
    q.push({src,-1});
    visited[src] = true;
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto itr: adj[node]){
            if(!visited[itr]){
                q.push({itr, node});
                visited[itr]=true;
            }
            else if(parent != itr){
                return true;
            }
        }
    }
    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(checkCycle(i, visited, adj)) return true;
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