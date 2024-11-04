#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> out, in;

        for (auto &c : connections)
        {
            out[c[0]].push_back(c[1]);
            in[c[1]].push_back(c[0]);
        }

        queue<int> q;
        unordered_map<int,int> vis;
        vis[0] = 1;

        q.push(0);
        int ans = 0;

        while (!q.empty())
        {
            int ele = q.front();
            q.pop();
            for(auto &x: out[ele])
            {
                if(vis[x])
                    continue;
                ans++;
                q.push(x);
                vis[x] = 1;
            }
            for(auto &x: in[ele])
            {
                if(vis[x])
                    continue;
                q.push(x);
                vis[x] = 1;
            }
        }
        return ans;
    }
};
