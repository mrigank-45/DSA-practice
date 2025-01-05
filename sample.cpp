#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> temp(maxi + 1, 0);

        for (int i = 0; i < n; i++)
        {
            temp[nums[i]]++;
        }

        int maxGap = 0;
        int prev = -1;
        for(int i = 1; i < temp.size(); i++)
        {
            if(temp[i] == 0)
                continue;
            if(prev == -1)
                prev = i;
            else{
                maxGap = max(maxGap, i - prev);
                prev = i;
            }
            
        }
        return maxGap;
    }
};
