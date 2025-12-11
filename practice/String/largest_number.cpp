// Largest Number - LeetCode
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> arr;
        for (int num : nums)
        {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), [](string &a, string &b)
             { return a + b > b + a; });  // a = 54, b = 546, a+b = 54546, b+a = 54654, so 546 comes first

        string ans = "";

        for (string s : arr)
        {
            ans += s;
        }

        if (ans.size() > 0 && ans[0] == '0')
        {
            return "0";
        }

        return ans;
    }
};
