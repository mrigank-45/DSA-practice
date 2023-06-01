// Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum.

// Kadane’s Algorithm: A subarray with a sum less than 0 will always reduce our answer and so this type of subarray 
// cannot be a part of the subarray with maximum sum.
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; 
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2,-3,-1,-5};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
