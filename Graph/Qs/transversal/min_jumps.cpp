// Minimum Jumps to Reach End via Prime Teleportation
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxi;

    vector<bool> sieve()
    {
        vector<bool> is_Prime(maxi, true);
        is_Prime[0] = false;
        is_Prime[1] = false;

        for (int i = 2; i * i < maxi; i++)
        {

            if (is_Prime[i])
            {

                for (int j = i * i; j < maxi; j = j + i)
                {

                    is_Prime[j] = false;
                }
            }
        }
        return is_Prime;
    }

    vector<int> primefactors(int x, vector<bool> &is_Prime)
    {
        vector<int> ans;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0 && is_Prime[i])
            {

                ans.push_back(i);
                while (x % i == 0)
                    x = x / i;
            }
        }
        if (x > 1)
            ans.push_back(x);
        return ans;
    }
    int minJumps(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vis(n, false);
        queue<pair<int, int>> q;            // store number of steps, current_index
        unordered_map<int, vector<int>> mp; // map to store the corresonding relation for each index

        maxi = *max_element(nums.begin(), nums.end()) + 1;

        vector<bool> is_Prime = sieve();

        for (int i = 0; i < n; i++)
        {
            vector<int> c = primefactors(nums[i], is_Prime);
            for (int p : c)
            {

                mp[p].push_back(i);
            }
        }
        q.push({0, 0});

        while (!q.empty())
        {
            int steps = q.front().first;
            int i = q.front().second;

            q.pop();
            if (i == n - 1)
                return steps;
            if (i + 1 < n && !vis[i + 1])
            {
                vis[i + 1] = true;
                q.push({steps + 1, i + 1});
            }

            if (i - 1 >= 0 && !vis[i - 1])
            {
                vis[i - 1] = true;
                q.push({steps + 1, i - 1});
            }

            if (is_Prime[nums[i]])
            {

                int x = nums[i];
                if (mp.count(x))
                {
                    for (auto it : mp[x])
                    {
                        if (!vis[it])
                        {
                            vis[it] = true;
                            q.push({steps + 1, it});
                        }
                    }
                }
                mp.erase(x);  // avoid visiting the same prime factor again
            }
        }

        return -1;
    }
};
