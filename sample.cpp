#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.find(nums[i]) == st.end())
            {
                st.insert(nums[i]);
                ans += st.size() - 1;
            }
            else
            {
                ans += st.size() - 1;
            }
        }
        return ans;
    }
};
