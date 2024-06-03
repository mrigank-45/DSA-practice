#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int index, int n, int m, int l, vector<vector<int>> &vis, vector<vector<int>> &dir)
    {
        if (index == l)
        {
            return true;
        }
        for (int d = 0; d < 4; d++)
        {
            int ni = i + dir[d][0];
            int nj = j + dir[d][1];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && vis[ni][nj] == 0 && board[ni][nj] == word[index])
            {
                vis[ni][nj] = 1;
                if (dfs(board, word, ni, nj, index + 1, n, m, l, vis, dir))
                {
                    return true;
                }
                vis[ni][nj] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        int l = word.length();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    if (dfs(board, word, i, j, 1, n, m, l, vis, dir))
                    {
                        return true;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};
