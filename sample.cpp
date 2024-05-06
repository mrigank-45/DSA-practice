#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i], 0});
            v.push_back({dep[i], 1});
        }

        sort(v.begin(), v.end());

        int temp = 0;
        int ans = 0;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second == 0)
            {
                temp++;
                ans = max(ans, temp);
            }
            else{
                temp--;
            }
        }

        return ans;
    }
};
