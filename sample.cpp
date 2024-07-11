#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size(), m = arr2.size();
        map<string, int> mp;

        for (int i = 0; i < m; i++)
        {
            string temp = "";
            string s = to_string(arr2[i]);
            for (int j = 0; j < s.size(); j++)
            {
                temp += s[j];
                mp[temp]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            string temp = "";
            string s = to_string(arr1[i]);
            for (int j = 0; j < s.size(); j++)
            {
                temp += s[j];
                if (mp[temp] > 0)
                {
                    ans = max(ans, (int)temp.size());
                }
            }
            if (mp[temp] > 0)
            {
                ans = max(ans, (int)temp.size());
            }
        }
        return ans;
    }
};
