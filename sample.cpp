#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string s)
    {
        int n = s.length();
        string ans = "";
        vector<int> d_cnt(n + 1, 0);
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'D')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            d_cnt[i] = cnt;
        }

        int temp = d_cnt[0] + 1;
        int next = temp + 1;
        ans += to_string(temp);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'D')
            {
                temp--;
                ans += to_string(temp);
            }
            else
            {
                temp = next;
                temp += d_cnt[i + 1];
                ans += to_string(temp);
                next = temp + 1;
            }
        }
        return ans;
    }
};
