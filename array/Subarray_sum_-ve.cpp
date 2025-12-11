#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();

    // sum -> index
    map<int, int> prefixSumMap;

    int ans = 0;
    int sum = 0;

    // Assign -1 to 'prefixSumMap[ 0 ]'.
    prefixSumMap[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        // If the value 'SUM' - 'K' is already present in the hashtable
        // then update the value of 'ANS' with maximum of 'ANS' and
        // 'i' - 'prefixSumMap[ SUM - K ]'.
        if (prefixSumMap.find(sum - k) != prefixSumMap.end())
        {
            ans = max(ans, i - prefixSumMap[sum - k]);
        }

        // If the value of 'SUM' is not present in the hashtable then
        // do 'prefixSumMap[ SUM ]' = 'i'
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }

    // Return the value of variable 'ANS'.
    return ans;
}
