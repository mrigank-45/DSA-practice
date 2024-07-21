#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        int n = arr.size();

        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            int m = s.size();
            // generate all substrings of s
            for (int j = 0; j < m; j++)
            {
                for (int k = 1; k <= m - j; k++)
                {
                    string sub = s.substr(j, k);
                    mp[sub]++;
                }
            }
        }

        vector<string> ans;

        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            int m = s.size();
            map<string, int> freq;
            for (int j = 0; j < m; j++)
            {
                for (int k = 1; k <= m - j; k++)
                {
                    string sub = s.substr(j, k);
                    freq[sub]++;
                }
            }
            bool flag = true;
            for (auto it : freq)
            {
                if (mp[it.first] - it.second == 0)
                {
                    if (flag)
                    {
                        ans.push_back(it.first);
                    }
                    else
                    {
                        if(it.first.size() < ans.back().size())
                        {
                            ans.pop_back();
                            ans.push_back(it.first);
                        }
                    }
                    flag = false;

                }
            }
            if (flag)
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};
