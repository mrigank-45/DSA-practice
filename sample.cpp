#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &start, int mid, int d)
    {
        int n = start.size();
        long long prev = start[0];
        for (int i = 1; i < n; i++)
        {
            long long curr = prev + mid;
            if (start[i] > curr)
            {
                prev = start[i];
            }
            else if (start[i] + d < curr)
            {
                return false;
            }
            else
            {
                prev = curr;
            }
        }

        return true;
    }
    int maxPossibleScore(vector<int> &start, int d)
    {
        int n = start.size();
        sort(start.begin(), start.end());

        if (d == 0)
        {
            int min_diff = INT_MAX;
            for (int i = 1; i < n; i++)
            {
                min_diff = min(min_diff, start[i] - start[i - 1]);
            }
            return min_diff;
        }

        long long low = 0;
        long long high = start[n-1] + d - start[0];

        long long mid = low + (high - low) / 2;
        int ans = -1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (possible(start, mid, d))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
