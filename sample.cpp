#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool outOfBounds(int i, int j, int n, int m)
    {
        return i < 0 || j < 0 || i >= n || j >= m;
    }

    int solve(vector<vector<char>> &mat, string target, int i, int j, int n, int m, int k)
    {
        if(mat[i][j] == '0') return 0;
        if (k == target.size())
        {
            return 1;
        }

        int ans = 0;

        char c = mat[i][j];
        mat[i][j] = '0';

        if (!outOfBounds(i, j + 1, n, m) && mat[i][j + 1] == target[k])
        {
            ans += solve(mat, target, i, j + 1, n, m, k + 1);
        }
        if (!outOfBounds(i, j - 1, n, m) && mat[i][j - 1] == target[k])
        {
            ans += solve(mat, target, i, j - 1, n, m, k + 1);
        }
        if (!outOfBounds(i + 1, j, n, m) && mat[i + 1][j] == target[k])
        {
            ans += solve(mat, target, i + 1, j, n, m, k + 1);
        }
        if (!outOfBounds(i - 1, j, n, m) && mat[i - 1][j] == target[k])
        {
            ans += solve(mat, target, i - 1, j, n, m, k + 1);
        }

        mat[i][j] = c;

        return ans;
    }
    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == target[0])
                {
                    count += solve(mat, target, i, j, n, m, 1);
                }
            }
        }

        return count;
    }
};
