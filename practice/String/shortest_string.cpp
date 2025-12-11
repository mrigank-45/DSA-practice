// Shortest String That Contains Three Strings

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string f(string x, string y)
    {
        int mi = min(x.length(), y.length());
        if (x.find(y) != string::npos)
            return x; // If y string exist in x string, then no need to merge
        string t = "";
        for (int j = mi; j >= 0; j--)
        {
            bool p = y.substr(0, j) == x.substr(x.length() - j); // If matching substring found
            if (p == 1)
                return x + y.substr(j); // If match found
        }
        return x + y; // if not matching
    }

    string minimumString(string a, string b, string c)
    {
        int n = 3;
        vector<string> dp = {a, b, c};
        string ans = "";
        // To test out all 6 possible permuation
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    bool c = i != k and i != j and j != k; // To generate unique sets of strings for merging
                    if (c)
                    {
                        string p = f(dp[i], dp[j]);
                        string q = f(p, dp[k]);
                        bool t1 = ans.empty();                            // If ans string is empty
                        bool t2 = q.length() < ans.length();              // If ans string is greater than the new final string
                        bool t3 = q.length() == ans.length() and ans > q; // If length of ans==length of final new string and ans string is lexicographically larger than new string
                        if (t1 or t3 or t2)
                            ans = q;
                    }
                }
            }
        }
        return ans; // final ans
    }
};
