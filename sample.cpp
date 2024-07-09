#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        int n = nums.size();
        int m = pattern.size();
        int i = 0, prev = 0, k = 0;
        int cnt = 0;

        while (i < n - 1)
        {
            if (pattern[k] == 1)
            {
                if (nums[i] < nums[i + 1])
                {
                    i++;
                    k++;
                    if (k == m)
                    {
                        cnt++;
                        k = 0;
                        i = prev + 1;
                        prev = i;
                    }
                }
                else
                {
                    i = prev + 1;
                    prev = i;
                    k = 0;
                }
            }
            else if (pattern[k] == -1)
            {
                if (nums[i] > nums[i + 1])
                {
                    i++;
                    k++;
                    if (k == m)
                    {
                        cnt++;
                        k = 0;
                        i = prev + 1;
                        prev = i;
                    }
                }
                else
                {
                    i = prev + 1;
                    prev = i;
                    k = 0;
                }
            }
            else
            {
                if (nums[i] == nums[i + 1])
                {
                    i++;
                    k++;
                    if (k == m)
                    {
                        cnt++;
                        k = 0;
                        i = prev + 1;
                        prev = i;
                    }
                }
                else
                {
                    i = prev + 1;
                    prev = i;
                    k = 0;
                }
            }
        }

        return cnt;
    }
};
