#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long solve(vector<int> &a, vector<int> &b, int i, int turn, int n)
    {
        if (i == n)
        {
            return 0;
        }

        long long ans = INT_MIN;

        if (turn == 0)
        {
            ans = max(a[i] + solve(a, b, i + 1, 0, n), ans);
            ans = max(solve(a, b, i + 1, 1, n), ans);
        }
        else
        {
            ans = max(b[i] + solve(a, b, i + 1, 1, n), ans);
            ans = max(solve(a, b, i + 1, 0, n), ans);
        }

        return ans;
    }
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();

        return max(solve(energyDrinkA, energyDrinkB, 0, 0, n), solve(energyDrinkB, energyDrinkA, 0, 1, n));
    }
};
