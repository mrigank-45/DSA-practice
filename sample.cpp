#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = difficulty.size(), m = worker.size(), ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({profit[i], difficulty[i]});
        }
        sort(v.rbegin(), v.rend());
        sort(worker.rbegin(), worker.rend());
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            while (i < m && worker[i] >= v[j].second)
            {
                ans += v[j].first;
                i++;
            }
            j++;
        }
        return ans;
    }
};
