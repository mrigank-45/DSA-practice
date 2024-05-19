#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLaptops(int n, int start[], int end[])
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), [](const auto &a, const auto &b) { return a.first < b.first; });

        int ans = 1;

        for (auto it : v)
        {
            if (pq.empty())
            {
                pq.push(it.second);
            }
            else
            {
                if (pq.top() <= it.first)
                {
                    pq.pop();
                }
                pq.push(it.second);
            }

            ans = max(ans, (int)pq.size());
        }

        return ans;
    }
};
