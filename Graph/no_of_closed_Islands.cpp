// Problem Statement
// https://leetcode.com/problems/number-of-closed-islands/

class Solution
{

public:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0)
            return;
        grid[i][j] = 2;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int con = 2;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (grid[i][j] == 0)
                        dfs(grid, i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0)
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};