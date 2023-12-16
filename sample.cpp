#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        map<int, int> frq;
        int cnt = 0; 
        long long int sum = 0;
        long long int ans = 0;

        for (int i = 0; i < k; i++)
        {
            if (frq[nums[i]] == 0)
            {
                cnt++;
            }
            frq[nums[i]]++;
            sum += nums[i];
        }

        int i = 0;
        int j = k - 1;

        while (j < nums.size())
        {
            if (cnt >= m)
            {
                ans = max(ans, sum);
            }

            if (frq[nums[i]] == 1)
            {
                cnt--;
            }
            frq[nums[i]]--;

            sum -= nums[i];
            i++;
            j++;
            if (j == nums.size())
            {
                break;
            }
            if (frq[nums[j]] == 0)
            {
                cnt++;
            }
            frq[nums[j]]++;
            sum += nums[j];
        }

        return ans;
    }
};
