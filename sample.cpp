#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int last = nums[0];
        vector<int> len;

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                if (nums[i] != last)
                {
                    len.push_back(i - start + 1);
                }
            }
            if (nums[i] == last)
            {
                if (i - start > 1)
                {
                    len.push_back(i - start);
                }
                start = i;
            }
            last = nums[i];
        }

        long long ans = 0;

        for (int i = 0; i < len.size(); i++)
        {
            long long temp;
            if(len[i] % 2 == 0){
                temp = len[i] / 2;
                temp = temp * (len[i] + 1);
            }
            else{
                temp = (len[i] - 1) / 2;
                temp = temp * len[i];
            }
            ans += temp;
        }

        return ans + n;
    }
};
