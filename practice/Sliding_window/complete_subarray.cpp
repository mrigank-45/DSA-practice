// Count Complete Subarrays in an Array
// Intution: If a subrray 's1' is Complete then including that subarray to another subarray 's2' will still make 's2' complete.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int i = 0, j = 0;
        map<int, int> Mp;
        map<int, int> M;

        for (int i = 0; i < nums.size(); i++)
        {
            Mp[nums[i]]++;
        }

        int unique = Mp.size(); // get the total unique elements
        int n = nums.size();
        int ans = 0;

        while (j < nums.size())
        {
            M[nums[j]]++;

            if (M.size() < unique) // check if current window has less number of unique elements
            {
                j++;
            }
            else if (M.size() == unique)
            {
                ans += n - j; // n-j subarrays can be made using s1 subarray
                while (M.size() == unique)
                {
                    M[nums[i]]--;
                    if (M[nums[i]] == 0)
                        M.erase(nums[i]);

                    // still after removing i'th element check whether still it is complete subarray, if it is then add it to ans.

                    if (M.size() == unique)
                        ans += n - j;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
