#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        int n = points.size();

        if (n == 1)
        {
            return 1;
        }

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int ans = 1;

        int start = points[0][0];
        int end = points[0][1];

        for (int i = 1; i < n; i++)
        {
            if (points[i][0] <= end)
            {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
            else
            {
                ans++;
                start = points[i][0];
                end = points[i][1];
            }
        }

        return ans;
    }
};
