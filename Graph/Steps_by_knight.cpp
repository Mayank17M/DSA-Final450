/**
 * Minimum steps to reach target by a Knight.
 * 
 * Reference: 
 *  https://www.youtube.com/watch?v=DD-_hZwEkXY
 *  https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/
 */ 

#include<bits/stdc++.h>
using namespace std;

struct cell {
    int x,y;
    int dis;
    cell() {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

bool isInside(int x, int y, int N) {
    if(x>=1 && y>=1 && x<=N && y<= N) return true;
    return false;
}

//Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
    // Code here
    int dx[]={-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[]={-1, -2, -2, -1, 1, 2, 2, 1};
    
    queue<cell> q;
    q.push(cell(KnightPos[0], KnightPos[1], 0));
    
    cell temp;
    int x, y;
    vector<vector<int>> visit(N+1, vector<int>(N+1, 0));
    visit[KnightPos[0]][KnightPos[1]] = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.x == TargetPos[0] && temp.y == TargetPos[1]){
            return temp.dis;
        }
        
        for(int i=0; i<8; i++){
            x = temp.x + dx[i];
            y = temp.y + dy[i];
            
            if(isInside(x,y,N) && !visit[x][y]){
                visit[x][y] = 1;
                q.push(cell(x, y, temp.dis+1));
            }
        }
    }
    return temp.dis;
}

int main() {
    int N = 30;
    vector<int> knightPos = { 1, 1 };
    vector<int> targetPos= { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}
