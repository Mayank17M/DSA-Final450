// Problem Statement
// https://leetcode.com/problems/surrounded-regions/

class Solution
{
public:
    void help(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = '#';
        help(board, i + 1, j);
        help(board, i, j + 1);
        help(board, i - 1, j);
        help(board, i, j - 1);
    }

public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != 'O')
            return;
        board[i][j] = 'X';
        dfs(board, i + 1, j);
        dfs(board, i, j + 1);
        dfs(board, i - 1, j);
        dfs(board, i, j - 1);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        //top row
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (board[i][j] == 'O')
                        help(board, i, j);
                }
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (board[i][j] == 'O')
                    ;
                dfs(board, i, j);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};