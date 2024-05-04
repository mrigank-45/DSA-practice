#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(int mid, vector<int> &quantities, int n)
    {
        if(mid == 0){
            return false;
        }
        int m = quantities.size();
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += quantities[i]/ mid + (quantities[i] % mid != 0 ? 1 : 0);
        }
        return sum <= n;
    }

    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int maxi = *max_element(quantities.begin(), quantities.end());

        int s = 0, e = maxi;
        int mid = (s + e) / 2;
        int ans = 0;
        while (s < e)
        {
            if (possible(mid, quantities, n))
            {
                e = mid;
                ans = mid;
            }
            else
            {
                s = mid + 1;
            }

            mid = (s + e) / 2;
        }
        if(ans == 0){
            return maxi;
        }
        return ans;
    }
};
