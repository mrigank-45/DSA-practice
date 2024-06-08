#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void markBorderConnected(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O')
        {
            return;
        }
        board[i][j] = '1';
        markBorderConnected(board, i - 1, j);
        markBorderConnected(board, i + 1, j);
        markBorderConnected(board, i, j - 1);
        markBorderConnected(board, i, j + 1);
    }

    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();

        // Mark all 'O's on the border and connected to border
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                markBorderConnected(board, i, 0);
            if (board[i][m - 1] == 'O')
                markBorderConnected(board, i, m - 1);
        }
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                markBorderConnected(board, 0, j);
            if (board[n - 1][j] == 'O')
                markBorderConnected(board, n - 1, j);
        }

        // Process the entire board to capture surrounded regions
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X'; // Capture surrounded region
                }
                else if (board[i][j] == '1')
                {
                    board[i][j] = 'O'; // Restore border-connected region
                }
            }
        }
    }
};
