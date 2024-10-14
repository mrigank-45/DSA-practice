#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> prefix_X(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> prefix_Y(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= cols; ++j)
            {
                prefix_X[i][j] = prefix_X[i - 1][j] + prefix_X[i][j - 1] - prefix_X[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                prefix_Y[i][j] = prefix_Y[i - 1][j] + prefix_Y[i][j - 1] - prefix_Y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }

        int result = 0;

        for (int r2 = 0; r2 < rows; ++r2)
        {
            for (int c2 = 0; c2 < cols; ++c2)
            {
                int x_count = 0, y_count = 0;

                x_count = prefix_X[r2 + 1][c2 + 1];
                y_count = prefix_Y[r2 + 1][c2 + 1];

                if (x_count > 0 && x_count == y_count)
                {
                    result++;
                }
            }
        }

        return result;
    }
};
