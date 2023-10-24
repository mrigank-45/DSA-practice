#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int helper(long long int maxIndex, vector<int> &maxHeights)
    {
        long long int sum = maxHeights[maxIndex];
        long long int curr = maxIndex + 1;
        long long int maxi1 = maxHeights[maxIndex];

        while (curr < maxHeights.size())
        {
            if (maxHeights[curr] <= maxi1)
            {
                sum += maxHeights[curr];
                maxi1 = maxHeights[curr];
            }
            else
            {
                sum += maxi1;
            }
            curr++;
        }

        long long int curr1 = maxIndex - 1;
        long long int maxi2 = maxHeights[maxIndex];

        while (curr1 >= 0)
        {
            if (maxHeights[curr1] <= maxi2)
            {
                sum += maxHeights[curr1];
                maxi2 = maxHeights[curr1];
            }
            else
            {
                sum += maxi2;
            }
            curr1--;
        }

        return sum;
    }

    long long maximumSumOfHeights(vector<int> &maxHeights)
    {

        long long int ans = INT_MIN;

        for (long long int i = 0; i < maxHeights.size(); i++)
        {
            long long int curr = helper(maxHeights[i], maxHeights);
            ans = max(ans, curr);
        }
        return ans;
    }
};
