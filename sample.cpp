#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minimizeStringValue(string s)
    {
        int n = s.size();

        map<char, int> mp;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            mp['a' + i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
            {
                mp[s[i]]++;
            }
            else
            {
                cnt++;
            }
        }

        vector<char> v;

        for (int i = 0; i < cnt; i++)
        {
            int mini = INT_MAX;
            char temp = 'a';

            for (auto it : mp)
            {
                if (it.second == 0)
                {
                    temp = it.first;
                    break;
                }
                if (it.second < mini)
                {
                    mini = it.second;
                    temp = it.first;
                }
            }

            cout << temp << endl;
            v.push_back(temp);
            mp[temp]++;
        }
        sort(v.begin(), v.end());

        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};
