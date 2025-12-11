// Maximum Palindromes After Operations

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPalindromesAfterOperations(vector<string> &words)
    {
        map<char, int> mp;
        vector<int> sizes;
        for (auto val : words)
        {
            sizes.push_back(val.length());
            for (auto &s : val)
                mp[s]++;
        }

        sort(sizes.begin(), sizes.end());
        
        int even = 0;
        int odd = 0;
        for (auto val : mp)
        {
            if (val.second % 2)
            {
                even += (val.second - 1);
                odd++;
            }
            else
            {
                even += val.second;
            }
        }
        int ans = 0;
        
        // check for many this length palindromes can be formed
        for (int i = 0; i < sizes.size(); i++)
        {
            if (sizes[i] % 2)
            {
                if (even >= sizes[i] - 1)
                {
                    if (even == (sizes[i] - 1) && odd < 1)
                        continue;
                    ans++;

                    if (odd >= 1)
                    {
                        odd--;
                    }
                    else
                    {
                        even -= 2;
                        odd++;
                    }

                    even -= ((sizes[i] - 1));
                }
            }
            else
            {
                if (even >= (sizes[i]))
                {

                    ans++;
                    even -= (sizes[i]);
                }
            }
        }
        return ans;
    }
};
