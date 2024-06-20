// Construct Smallest Number From DI String
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.size();

        vector<int> temp(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int cnt = 0;
            while (j < n && pattern[j] == 'D')
            {
                j++;
                cnt++;
            }
            temp[i] = cnt;
        }

        int mini = 1;
        string ans = "";

        for (int i = 0; i <= n; i++)
        {
            if (i != 0 && pattern[i - 1] == 'D') // pattern[i-1] == 'D'
            {
                ans.push_back(ans.back() - 1);
            }
            else
            {
                if (temp[i] == 0)  // pattern[i] == 'I' and pattern[i-1] == 'I'
                {
                    ans += to_string(mini);
                    mini++;
                }
                else // pattern[i] == 'D' and pattern[i-1] == 'I'
                {
                    ans += to_string(mini + temp[i]);
                    mini = mini + temp[i] + 1;
                }
            }
        }

        return ans;
    }
};
