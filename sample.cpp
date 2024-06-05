#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> mp;

        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                int sum = nums[i] + nums[j];
                if(mp.find(-sum) != mp.end())
                {
                    vector<int> temp = mp[-sum];
                    for(auto it: temp){
                        vector<int> temp1 = {nums[i],nums[j],nums[it]};
                        sort(temp1.begin(),temp1.end());
                        res.push_back(temp1);
                    }
                }
            }
        }

        return res;
    }
};
