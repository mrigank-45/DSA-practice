#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        vector<int> v(n, -1);

        for (int i = 0; i < n; i++)
        {
            int minutes = (stoi(timePoints[i].substr(0, 2)) * 60) + stoi(timePoints[i].substr(3, 2));
            v[i] = minutes;
        }
        sort(v.begin(), v.end());
        int minDiff = ((24 * 60) + v[0]) - v[n - 1];
        for(int i = 1; i < n; i++)
        {
            minDiff = min(minDiff, v[i] - v[i - 1]);
        }
        return minDiff;
    }
};
