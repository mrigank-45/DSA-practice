#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> subarray_id(n);
        int current_id = 0;

        subarray_id[0] = current_id;

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] % 2 != nums[i - 1] % 2)
            {
                subarray_id[i] = current_id;
            }
            else
            {
                current_id++;
                subarray_id[i] = current_id;
            }
        }

        vector<bool> ans;
        for (const auto &query : queries)
        {
            int l = query[0];
            int r = query[1];
            ans.push_back(subarray_id[l] == subarray_id[r]);
        }

        return ans;
    }
};
