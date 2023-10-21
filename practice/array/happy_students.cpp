// Happy Students
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countWays(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        int selected = 0;

        if (nums[0] != 0) // Not Selecting AnyOne
        {
            ans = 1;
        }

        for (int i = 0; i < n; i++)
        {
            selected++;
            if (selected > nums[i])
            {                                            
                if (i + 1 < n && selected < nums[i + 1]) // Considering from (i+1) to n Students is not Selected.
                {
                    ans++;
                }
                else if (i + 1 == n) // Last Student
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
