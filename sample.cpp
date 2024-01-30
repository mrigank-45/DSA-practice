#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries)
    {
        map<int, vector<int>> mp; // {time, all servers}

        for (auto i : logs)
        {
            mp[i[1]].push_back(i[0]);
        }

        map<int, int> vis; // {server, count of queries in window}

        int servers = 0;

        // max and min of queries
        int l = *min_element(queries.begin(), queries.end()) - x;
        int r = *min_element(queries.begin(), queries.end());

        for (int i = l; i <= r; i++)
        {
            if (mp.find(i) != mp.end()) // if found
            {
                for (auto j : mp[i])
                {
                    if (vis.find(j) == vis.end() || vis[j] == 0) // not already visited in this window
                    {
                        vis[j] = 1;
                        servers++;
                    }
                    else // else increase the count of vis
                    {
                        vis[j]++;
                    }
                }
            }
        }

        map<int, int> ans; // {window right, count of unused servers in windo}
        ans[r] = n - servers;

        while (r <= *max_element(queries.begin(), queries.end()))
        {
            // for l++
            if (mp.find(l) != mp.end()) // if found
            {
                for (auto j : mp[l])
                {
                    vis[j]--;
                    if (vis[j] == 0) // no longer in window
                    {
                        servers--;
                    }
                }
            }

            // for r++
            if (mp.find(r + 1) != mp.end()) // if found
            {
                for (auto j : mp[r + 1])
                {
                    if (vis.find(j) == vis.end() || vis[j] == 0) // not already visited in this window
                    {
                        vis[j] = 1;
                        servers++;
                    }
                    else // else increase the count of vis
                    {
                        vis[j]++;
                    }
                }
            }

            l++;
            r++;
            ans[r] = n - servers;
        }

        vector<int> res;

        for (int i = 0; i < queries.size(); i++)
        {
            res.push_back(ans[queries[i]]);
        }

        return res;
        
    }
};
