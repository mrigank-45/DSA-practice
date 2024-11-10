#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.size();

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        vector<int> ans;

        int len = 0;
        unordered_map<char, int> temp;

        for(int i = 0; i < n; i++)
        {
            len++;
            temp[s[i]]++;

            bool flag = true;
            for(auto x : temp)
            {
                if(x.second != mp[x.first])
                {
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(len);
                len = 0;
                temp.clear();
            }
        }

        return ans;
    }
};
