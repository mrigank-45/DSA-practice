#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int i, int j, string &s)
    {
        int num = 0, test = 1;
        for (int k = j; k >= i; k--) // Converting Binary to Decimal
        {
            if (s[k] == '1')
                num += test;
            test *= 2;
        }
        while (num > 1) // Checking if num is a power of 5
        {
            if (num % 5)
                return false;
            num /= 5;
        }
        return num == 1;
    }
    int recursion(int index, string &s, vector<int> &dp)
    {
        if (index == s.length()) // End of partitioning
        {
            return 0;
        }
        if (s[index] == '0') // Invalid Case
            return INT_MAX;

        if (dp[index] != 1e5)
            return dp[index];
        int ans = INT_MAX;
        for (int j = index; j < s.length(); j++)
        {
            if (check(index, j, s))
            {
                ans = min(ans, 1 + recursion(j + 1, s, dp));
            }
        }
        // Memoize the minimum value at the current index
        return dp[index] = ans;
    }

public:
    int minimumBeautifulSubstrings(string s)
    {
        vector<int> dp(s.length(), 1e5);
        int ans = recursion(0, s, dp);
        if (ans > 15)
        {
            return -1;
        }
        return ans;
    }
};
