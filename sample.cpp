#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
    {
        map<int, vector<int>> mp;

        for (auto i : logs)
        {
            mp[i[0]].push_back(i[1]);
        }

        map<int, int> vis;

        int servers = 0;
        int l = queries[0] - x;
        int r = queries[0];

        for (int i = queries[0] - x; i <= queries[0]; i++)
        {
            if (mp.find(i) != mp.end()) // if found
            {
                for (auto j : mp[i])
                {
                    if (vis.find(j) == vis.end()) // not already visited in this window
                    {
                        vis[j] = 1;
                        servers++;
                    }
                    else                         // else increase the count of vis
                    {
                        vis[j]++;
                    }
                }
            }
        }

        for (int i = 1; i < queries.size(); i++)
        {
            

            
        }
        
    }
};
