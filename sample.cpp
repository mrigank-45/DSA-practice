#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pq.push({grid[i][j], i});
            }
        }
        unordered_map<int, int> mp;

        long long ans = 0;
        while (!pq.empty() && k > 0)
        {
            int val = pq.top().first;
            int row = pq.top().second;
            pq.pop();

            if (mp[row] < limits[row])
            {
                ans += val;
                mp[row]++;
                k--;
            }
        }

        return ans;
    }
};
