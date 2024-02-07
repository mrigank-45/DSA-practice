#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if ((j - i >= indexDifference) && (abs(nums[j] - nums[i]) >= valueDifference))
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        if (ans.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};
