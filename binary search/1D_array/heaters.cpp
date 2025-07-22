// Heaters problem (leetcode)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int maxDist = 0, m = heaters.size();
        for (int i = 0, n = houses.size(); i < n; ++i)
        {
            int pos = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
            int dist1 = (pos == m) ? INT_MAX : abs(heaters[pos] - houses[i]);
            int dist2 = (pos == 0) ? INT_MAX : abs(heaters[pos - 1] - houses[i]);
            maxDist = max(maxDist, min(dist1, dist2));
        }
        return maxDist;
    }
};
