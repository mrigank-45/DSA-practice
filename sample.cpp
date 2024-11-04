#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = temperatures[i];
            while (!s.empty() && temperatures[s.top()] <= curr)
            {
                s.pop();
            }

            ans[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return ans;
    }
};
