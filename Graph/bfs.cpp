/**
 * Breadth first search for undirected graph.
 * References: https://www.youtube.com/watch?v=pcKY4hjDrxk
 */ 

#include <bits/stdc++.h>
#define pb push_back
 
using namespace std;
 
vector<bool> v;
vector<vector<int> > g;
 
void edge(int a, int b){
    g[a].pb(b);
 
    // for undirected graph add this line
    // g[b].pb(a);
}
 
void bfs(int src) {
    queue<int> q;
    q.push(src);
    v[src] = true;
    while(!q.empty()) {
        int key = q.front();
        q.pop();
        cout<<key<<" ";
        for(auto i = g[key].begin(); i != g[key].end(); i++){
            if(!v[*i]){
                q.push(*i);
                v[*i]=true;
            }
        }
    }
}
 
// Driver code
int main(){
    int n, e;
    cin >> n >> e;
 
    v.assign(n, false);
    g.assign(n, vector<int>());
 
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edge(a, b);
    }
 
    for (int i = 0; i < n; i++) {
        if (!v[i])
            bfs(i);
    }
 
    return 0;
}