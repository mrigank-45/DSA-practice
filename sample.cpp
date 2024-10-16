#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    const vector<pair<int, int>> knightMoves = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    bool isValid(int x, int y, int N)
    {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }

    double dp[101][26][26];

    double solve(int n, int k, int x, int y)
    {
        if (!isValid(x, y, n)) return 0.0;
        if (k == 0) return 1.0;

        if (dp[k][x][y] != -1) return dp[k][x][y];

        double ans = 0.0;
        for (auto move : knightMoves)
        {
            ans += solve(n, k - 1, x + move.first, y + move.second);
        }

        return dp[k][x][y] = ans;
    }

    double knightProbability(int n, int k, int row, int column)
    {
        memset(dp, -1, sizeof(dp));
        double ways = solve(n, k, row, column);
        return ways / pow(8, k);
    }
};
