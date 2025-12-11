// Subarray Product Less Than K

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        long long ans = 0;
        long long product = 1;
        int left = 0, right = 0;
        while (right < n)
        {
            product *= a[right];
            while (left <= right && product >= k)
            {
                product /= a[left];
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};
