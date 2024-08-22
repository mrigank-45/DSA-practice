#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> occurrencesOfElement(vector<int> &nums, vector<int> &queries, int x)
    {
        int n = nums.size();
        vector<int> index;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == x)
            {
                index.push_back(i);
            }
        }
        int size = index.size();

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++)
        {
            if (queries[i] > size)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(index[queries[i] - 1]);
            }
        }

        return ans;
    }
};
