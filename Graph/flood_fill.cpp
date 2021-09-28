/**
 * Flood Fill: https://leetcode.com/problems/flood-fill/
 */ 

#include<bits/stdc++.h>
using namespace std;

bool isValid(int sr, int sc, vector<vector<int>>& image){
    int m=image.size(); int n = image[0].size();
    if(sr>=0 && sc>=0 && sr<=m-1 && sc<=n-1) return true;
    return false;
}
    
void solve(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    image[sr][sc]= newColor;
    int nextsr, nextsc;
    for(int i=0;i<4; i++){
        nextsr = sr + dx[i];
        nextsc = sc + dy[i];
        if(isValid(nextsr, nextsc, image) && image[nextsr][nextsc]!=newColor && image[nextsr][nextsc]== oldColor){
            solve(image, nextsr, nextsc, oldColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    solve(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0}, {1,0,1}};
    int sr=1, sc=1;
    int newColor =2;
    vector<vector<int>> res = floodFill(image, sr, sc, newColor);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[0].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}