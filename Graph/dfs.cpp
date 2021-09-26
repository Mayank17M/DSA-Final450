/**
 * Depth first search for undirected graph.
 * References: 
 *  https://www.youtube.com/watch?v=pcKY4hjDrxk
 *  https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 */ 

#include <bits/stdc++.h>
using namespace std;
 
void dfs(int key, vector<bool> &visited, vector<int> &res, vector<int> adj[]){
    res.push_back(key);
    visited[key] = true;
    for(auto i: adj[key]){
        if(!visited[i]){
            dfs(i, visited, res, adj);
        }
    }
}
    
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V,false);
    vector<int> res;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i, visited, res, adj);
        }
    }
    return res;
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
        //adj[v].push_back(u);  For Undirected Graph add this line.
    }
    vector<int> dfs = dfsOfGraph(V, adj);
    for (auto i : dfs) {
        cout << dfs[i] << " ";
    }
    cout << endl;
    return 0;
}