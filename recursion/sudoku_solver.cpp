#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    bool isSafe(int row, int col, vector<vector<char>> &board, int val)
    {
        for (int i = 0; i < 9; i++)
        {
            // row check
            if (board[row][i] - '0' == val)
                return false;
            // col check
            if (board[i][col] - '0' == val)
                return false;
            // 3*3 matrix check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] - '0' == val)
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board[0].size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (board[row][col] == '.')
                {
                    for (int val = 1; val <= 9; val++)
                    {
                        if (isSafe(row, col, board, val))
                        {
                            board[row][col] = '0' + val;

                            int aageSolutionPossible = solve(board);
                            if (aageSolutionPossible)
                            {
                                return true;
                            }
                            else
                            {
                                // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};
