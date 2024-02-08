#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();

        vector<int> ans;

        pair<int, int> maxi = {nums[0], 0}; // {value, index}
        pair<int, int> mini = {nums[0], 0}; // {value, index}

        int i = 0;
        int j = indexDifference;

        while (j < n)
        {
            if (abs(nums[j] - maxi.first) >= valueDifference)
            {
                ans.push_back(maxi.second);
                ans.push_back(j);
                break;
            }
            else if (abs(nums[j] - mini.first) >= valueDifference)
            {
                ans.push_back(mini.second);
                ans.push_back(j);
                break;
            }
            else
            {
                i++;
                if(i >= n){
                    break;
                }
                if (nums[i] > maxi.first)
                {
                    maxi = {nums[i], i};
                }
                if (nums[i] < mini.first)
                {
                    mini = {nums[i], i};
                }
            }
            j++;
        }

        if (ans.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }

        return ans;
    }
};
