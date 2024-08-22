#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &a, vector<int> &b, int i, int turn, int n, vector<vector<long long>> &dp)
    {
        if (i == n)
        {
            return 0;
        }

        if (dp[i][turn] != -1)
        {
            return dp[i][turn];
        }

        long long ans = 0;

        if (turn == 0)
        {
            ans = max(a[i] + solve(a, b, i + 1, 0, n, dp), ans);
            ans = max(solve(a, b, i + 1, 1, n, dp), ans);
        }
        else
        {
            ans = max(b[i] + solve(a, b, i + 1, 1, n, dp), ans);
            ans = max(solve(a, b, i + 1, 0, n, dp), ans);
        }

        return dp[i][turn] = ans;
    }
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp1(n + 1, vector<long long>(2, -1));
        long long res = 0;
        res = max(res, solve(energyDrinkA, energyDrinkB, 0, 0, n, dp1));
        vector<vector<long long>> dp2(n + 1, vector<long long>(2, -1));
        res = max(res, solve(energyDrinkA, energyDrinkB, 0, 1, n, dp2));

        return res;
    }
};
