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
             { return a + b > b + a; });

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
