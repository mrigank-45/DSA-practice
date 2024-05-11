#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });

        int ans = 1;
        int e = v[0].second;

        for (int i = 1; i < n; i++)
        {
            if (v[i].first > e)
            {
                ans++;
                e = v[i].second;
            }
            else
            {
                if (v[i].second < e)
                {
                    e = v[i].second;
                }
            }
        }

        return ans;
    }
};
