#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int maxSumWithK(long long int arr[], long long int n, long long int k)
    {
        long long wsum = 0; // window sum
        for (int i = 0; i < k; i++)
        {
            wsum += arr[i];
        }

        long long ans = wsum;

        long long left_sum = 0; // sum of left of window if it is positive

        for (int i = k; i < n; i++)
        {
            wsum += arr[i];
            wsum -= arr[i - k];

            left_sum += arr[i - k];
            left_sum = max(left_sum, 0LL); // it is it is negative then we will not consider it

            ans = max(ans, wsum + left_sum);
        }

        return ans;
    }
};
