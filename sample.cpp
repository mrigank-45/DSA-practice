#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int n)
    {
        if (n == 1)
        {
            return "1";
        }

        string prev = solve(n - 1);
        string result = "";
        int i = 0;

        while (i < prev.size())
        {
            char c = prev[i];
            int cnt = 0;

            while (prev[i] == c && i < prev.size())
            {
                cnt++;
                i++;
            }
            result += to_string(cnt) + c;
        }

        return result;
    }
    string countAndSay(int n)
    {

        return solve(n);
    }
};
