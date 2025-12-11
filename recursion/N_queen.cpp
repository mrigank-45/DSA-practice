#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool isSafe(int row, int col, vector<vector<int>> &board, int n)
    {
        int x = row;
        int y = col;
        // row checking
        while (y >= 0)
        {
            if (board[x][y--] == 1)
            {
                return false;
            }
        }
        // diagonal 1 checking
        y = col;
        while (x >= 0 && y >= 0)
        {
            if (board[x--][y--] == 1)
            {
                return false;
            }
        }
        // diagonal 2 checking
        x = row;
        y = col;
        while (x < n && y >= 0)
        {
            if (board[x++][y--] == 1)
            {
                return false;
            }
        }
        return true;
    }

    void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string s;
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                {
                    s.push_back('Q');
                }
                else
                {
                    s.push_back('.');
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n)
    {
        if (col == n)
        {
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                // safe hai toh uss position ko mark karke next column par jao
                board[row][col] = 1;
                solve(col + 1, ans, board, n);
                // backtrack
                board[row][col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // matrix of n*n, initialize all elememts with 0.
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};
