#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        unordered_map<int, int> mp;
        vector<int> start;
        for (int i = 0; i < n; i++)
        {
            start.push_back(intervals[i][0]);
            mp[intervals[i][0]] = i;
        }
        sort(start.begin(),start.end());
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (lower_bound(start.begin(), start.end(), intervals[i][1]) != start.end())
            {
                int val = *lower_bound(start.begin(), start.end(), intervals[i][1]);
                ans.push_back(mp[val]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
