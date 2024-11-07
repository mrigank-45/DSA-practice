#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        int flag = 1;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '+')
            {
                flag = 1;
            }
            else if (s[i] == '-')
            {
                if (flag == -1)
                    flag = 1;
                else
                    flag = -1;
            }
            else if (s[i] == '(' || s[i] == ')' || s[i] == ' ')
            {
                continue;
            }
            else
            {
                int num = 0;
                while (i < n && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                ans += flag * num;
            }
        }

        return ans;
    }
};
