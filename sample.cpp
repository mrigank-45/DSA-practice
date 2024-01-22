#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(long long int n)
    {
        if (n == 0)
        {
            return true;
        }
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }
    int solve(string s, int i, string curr)
    {
        if (i == s.length())
        {
            long long int z = stoll(curr);
            if (check(z))
            {
                return 1;
            }
            return INT_MAX;
        }

        // no partition
        int c1 = solve(s, i + 1, curr + s[i]);

        // partition
        int c2 = INT_MAX;
        if (curr.length() != 0 && check(stoll(curr)) && (i == s.length() - 1 || s[i + 1] == '1'))
        {
            string temp = "";
            temp.push_back(s[i]);
            if (solve(s, i + 1, temp) == INT_MAX)
            {
                c2 = INT_MAX;
            }
            else
            {
                c2 = 1 + solve(s, i + 1, temp);
            }
        }
        return min(c1, c2);
    }
    int minimumBeautifulSubstrings(string s)
    {

        if (solve(s, 0, "") == INT_MAX || solve(s, 0, "") == 1)
        {
            return -1;
        }
        else
        {
            return solve(s, 0, "");
        }
    }
};
