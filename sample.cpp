#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        map<int, int> prefixSumMap;

        int ans = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 0) return true;
            sum += arr[i];
            if(sum == 0) return true;

            if (prefixSumMap.find(sum) != prefixSumMap.end())
            {
                return true;
                break;
            }

            if (prefixSumMap.find(sum) == prefixSumMap.end())
            {
                prefixSumMap[sum] = i;
            }
        }

        return false;
    }
};
