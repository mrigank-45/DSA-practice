#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        int n = s.size();
        string ans;

        for (int i = 0; i < n; i++)
        {
            if (k == 0)
            {
                ans.push_back(s[i]);
                continue;
            }
            int val1 = s[i] - 'a';
            int val2 = 26 - val1;

            if (val1 <= k && val1 < val2)
            {
                ans.push_back('a');
                k -= val1;
            }
            else if (val2 <= k && val2 <= val1)
            {
                ans.push_back('a');
                k -= val2;
            }
            else
            {
                char temp = s[i] - k;
                ans.push_back(temp);
                k = 0;
            }
        }

        return ans;
    }
};
