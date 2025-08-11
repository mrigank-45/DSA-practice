#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int i, vector<int> &price, vector<vector<int>> &special, vector<int> &needs, int n, int m)
    {
        if (i == m)
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                ans += needs[i] * price[i];
            }
            return ans;
        }

        // take
        int take = INT_MAX;
        bool canUse = true;
        for (int j = 0; j < n; j++)
        {
            if (needs[j] < special[i][j])
            {
                canUse = false;
                break;
            }
        }
        if (canUse)
        {
            for (int j = 0; j < n; j++)
            {
                needs[j] -= special[i][j];
            }
            take = special[i][n] + solve(i, price, special, needs, n, m);
            for (int j = 0; j < n; j++)
            {
                needs[j] += special[i][j];
            }
        }

        // not take
        int notTake = solve(i + 1, price, special, needs, n, m);

        return min(take, notTake);
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();
        int m = special.size();
        return solve(0, price, special, needs, n, m);
    }
};
