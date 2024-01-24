// Continuous Subarrays
// https://leetcode.com/problems/continuous-subarrays/solutions/3706716/c-simple-and-intuitive-sliding-window-detailed-explanation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        priority_queue<pair<long long int, long long int>> pqmx;                                             // value,index
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pqmn; // value,index

        long long int n = nums.size();
        long long int ans = 0, i = 0, j = 0;

        while (j < n)
        {
            pqmx.push({nums[j], j});
            pqmn.push({nums[j], j});

            while (i <= j)
            {
                // removing out of window elements
                while (!pqmx.empty() and pqmx.top().second < i)
                    pqmx.pop();
                while (!pqmn.empty() and pqmn.top().second < i)
                    pqmn.pop();

                // shifting the start position of window if the current window is not suitable i.e., abs diff. > 2
                if (!pqmx.empty() and !pqmn.empty() and abs(pqmx.top().first - pqmn.top().first) > 2)
                    i++;
                else
                    break;
            }

            ans += j - i + 1; // add count of a new(ending with nums[j]) valid subarrays
            j++;
        }
        return ans;
    }
};
