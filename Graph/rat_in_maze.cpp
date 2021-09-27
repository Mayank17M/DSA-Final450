/** 
 * Rat in a Maze Problem: 
 *  https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
 * References: 
 *  https://www.youtube.com/watch?v=bLGZhJlt4y0 
 */

#include <bits/stdc++.h>
#define MAX 5
using namespace std;

/**
 * Naive approach:

void solve(vector<string> &res, vector<vector<int>> &visit, vector<vector<int>> &m, int n, string path, int i, int j){
    if(i==n-1 && j==n-1){
        res.push_back(path);
        return;
    }
    
    //down
    if(i+1<n && !visit[i+1][j] && m[i+1][j]==1){
        visit[i][j]=1;
        solve(res, visit, m, n, path+'D', i+1, j);
        visit[i][j]=0;
    }
    
    //left
    if(j-1>0 && !visit[i][j-1] && m[i][j-1]==1){
        visit[i][j]=1;
        solve(res, visit, m, n, path+'L', i, j-1);
        visit[i][j]=0;
    }
    
    //right
    if(j+1<n && !visit[i][j+1] && m[i][j+1]==1){
        visit[i][j]=1;
        solve(res, visit, m, n, path+'R', i, j+1);
        visit[i][j]=0;
    }
    
    //up
    if(i-1>0 && !visit[i-1][j] && m[i-1][j]==1){
        visit[i][j]=1;
        solve(res, visit, m, n, path+'U', i-1, j);
        visit[i][j]=0;
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> res;
    vector<vector<int> > visit(n, vector<int>(n,0));
    if(m[0][0] == 1) solve(res, visit, m, n, "", 0, 0);
    return res;
}
*/

// Optimized approach:

void solve(vector<string> &res, vector<vector<int>> &visit, vector<vector<int>> &m, int n, string path, int i, int j, int di[], int dj[]){
    if(i==n-1 && j==n-1){
        res.push_back(path);
        return;
    }
    string dir = "DLRU";
    for(int idx=0; idx<4; idx++){
        int nexti = i+di[idx];
        int nextj = j+dj[idx];
        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visit[nexti][nextj] && m[nexti][nextj]==1){
            visit[i][j]=1;
            solve(res, visit, m, n, path+dir[idx], nexti, nextj, di, dj );
            visit[i][j]=0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> res;
    vector<vector<int> > visit(n, vector<int>(n,0));
    int di[]={1,0,0,-1};
    int dj[]={0,-1,1,0};
    if(m[0][0] == 1) solve(res, visit, m, n, "", 0, 0, di, dj);
    return res;
}

int main() {
    vector<vector<int>> m = { { 1, 0, 0, 0, 0 },
                            { 1, 1, 1, 1, 1 },
                            { 1, 1, 1, 0, 1 },
                            { 0, 0, 0, 0, 1 },
                            { 0, 0, 0, 0, 1 } };
    int n = m.size();
    vector<string> ans = findPath(m, n);
    for(auto itr: ans){
        cout<<itr<<" ";
    }
    return 0;
}