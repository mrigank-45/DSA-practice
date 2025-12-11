// Maximum Number of Alloys

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAffordable(long long int alloys, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        long long int minCost = INT_MAX;
        for (int i = 0; i < composition.size(); ++i)
        {
            long long int currCost = 0;
            for (int j = 0; j < composition[i].size(); ++j)
            {
                long long int curr = alloys * composition[i][j];
                if (stock[j] >= curr)
                    continue;
                else
                {
                    long long int extra = (curr - stock[j]) * cost[j];
                    currCost += extra;
                }
            }
            minCost = min(currCost, minCost); // min of all machines
        }
        return (minCost <= budget);
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        long long int low = 0, high = 1e9, ans = 0;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if (isAffordable(mid, budget, composition, stock, cost))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
