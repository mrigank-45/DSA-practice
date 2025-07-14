// Given an array and a sum k, we need to print the length of the longest subarray that sums to k. 
// (given elements of array are +ve only)
// 2 pointer Approach which both start from 0 index

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 1, 2, 4};
    long long k = 6;
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    int count = 0;
    while (right < n)
    {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k)
        {
            sum = sum - a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
            count++;
        }

        // Move forward the right pointer and add it's value
        right++;
        if (right < n)
        {
            sum = sum + a[right];
        }
    }

    cout << maxLen <<endl;
    cout << count <<endl;
    return 0;
}
