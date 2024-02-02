#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSizeSubarray(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> arr(2 * n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = nums[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr[i + n] = nums[i];
        }

        int i = 0, j = 0;

        int sum = arr[0];
        int ans = INT_MAX;

        while (i < 2 * n && j < 2 * n)
        {
            cout << i << ' ' << j << endl;
            cout << "sum: " << sum << endl;

            if (sum == target)
            {
                ans = min(ans, j - i + 1);
                if (i != j)
                {
                    sum = sum - arr[i];
                    i++;
                }
                else
                {
                    if (j != 2 * n - 1)
                    {
                        sum = sum + arr[j + 1];
                    }
                    j++;
                }
            }
            else if (sum < target)
            {
                if (j != 2 * n - 1)
                {
                    sum = sum + arr[j + 1];
                }
                j++;
            }
            else
            {
                if (i != j)
                {
                    sum = sum - arr[i];
                    i++;
                }
                else
                {
                    if (j != 2 * n - 1)
                    {
                        sum = sum + arr[j + 1];
                    }
                    j++;
                }
            }
        }

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
