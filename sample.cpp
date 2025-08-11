#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        int n = deadends.size();
        unordered_map<string, bool> mp;
        for (int i = 0; i < n; i++)
        {
            mp[deadends[i]] = true;
        }
        queue<string> q;
        unordered_map<string, bool> vis;
        q.push("0000");
        vis["0000"] = true;
        if (mp["0000"] || mp[target])
            return -1;
        if (target == "0000")
            return 0;
        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string s = q.front();
                q.pop();

                for (int j = 0; j < 4; j++)
                {
                    string s1 = s;
                    s1[j] = (s[j] == '9') ? '0' : s[j] + 1; 
                    if (s1 == target)
                        return ans + 1;
                    if (!vis[s1] && !mp[s1])
                    {
                        q.push(s1);
                        vis[s1] = true;
                    }

                    string s2 = s;
                    s2[j] = (s[j] == '0') ? '9' : s[j] - 1; 
                    if (s2 == target)
                        return ans + 1;
                    if (!vis[s2] && !mp[s2])
                    {
                        q.push(s2);
                        vis[s2] = true;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
