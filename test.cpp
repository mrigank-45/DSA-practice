#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false);
    prev[0] = true;

    if (arr[0] <= k)
    {
        prev[arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++)
    {
        vector<bool> cur(k + 1, false);
        cur[0] = true;

        for (int target = 1; target <= k; target++)
        {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
            {
                taken = prev[target - arr[ind]];
            }
            cur[target] = notTaken || taken;
        }

        prev = cur;
    }

    return prev[k];
}

int main()
{
    // Sample test case
    vector<int> arr = {1, 2, 3, 4, 5}; // The array elements
    int k = 9; // Target sum
    int n = arr.size();

    int ans = INT_MAX;

    // Iterate through all possible subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
            int subSize = subarray.size();
            if (subsetSumToK(subSize, k, subarray))
            {
                ans = min(ans, j - i + 1);
            }
        }
    }

    if (ans == INT_MAX)
    {
        cout << -1 << endl; // No subarray found
    }
    else
    {
        cout << ans << endl; // Minimum length of subarray with sum k
    }

    return 0;
}
