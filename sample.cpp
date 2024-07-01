#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool allowed(int val, int arr[], int n, int d)
    {
        int sum = 0;
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (sum > val)
            {
                return false;
            }
            if (sum + arr[i] > val)
            {
                cnt++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }
        return sum<=val && cnt <= d;
    }

    int leastWeightCapacity(int arr[], int n, int d)
    {
        if(n == 1){
            return arr[0];
        }

        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if(d == 1){
            return sum;
        }
        int s = mini, e = sum;
        int ans = 0;
        while (s < e)
        {
            int mid = (s + e) / 2;
            if (allowed(mid, arr, n, d))
            {
                ans = mid;
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};
