#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<pair<int, int>, pair<int, int>>> v;

        for (int i = 0; i < m; i++)
        {
            map<int, int> mp1;
            for (int j = 0; j < n; j++)
            {
                mp1[grid[j][i]]++;
            }
            priority_queue<pair<int, int>> pq;
            for (auto x : mp1)
            {
                pq.push({x.second, x.first});
            }
            pair<int, int> p1 = {pq.top().second, pq.top().first};
            pq.pop();
            pair<int, int> p2;
            if (pq.empty())
            {
                p2 = {-1, n};
            }
            else
            {
                p2 = {pq.top().second, pq.top().first};
            }
            v.push_back({p1, p2});
        }
        int ans = 0;
        int prev = -1;
        for (int i = 0; i < v.size(); i++)
        {
            pair<int, int> p1 = v[i].first;
            pair<int, int> p2 = v[i].second;
            if (prev == -1)
            {
                if (p1.first == p2.first && i != n - 1 && p1.first == v[i + 1].first.first)
                {
                    ans = ans + (n - p2.second);
                    prev = p2.first;
                }
                else
                {
                    ans = ans + n - p1.second;
                    prev = p1.first;
                }
            }
            else
            {
                if (prev == p1.first)
                {
                    if (p2.first == -1)
                    {
                        ans = ans + n;
                        prev = -1;
                    }
                    else
                    {
                        ans = ans + (n - p2.second);
                        prev = p2.first;
                    }
                }
                else
                {
                    ans = ans + (n - p1.second);
                    prev = p1.first;
                }
            }
        }

        return ans;
    }
};
