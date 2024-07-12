#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
    {
        int n = nums.size();
        int m = changeIndices.size();
        for (int i = 0; i < m; i++)
        {
            changeIndices[i] = changeIndices[i] - 1;
        }
        map<int, int> need;
        map<int, int> last;
        map<int, bool> vis;

        for (int i = 0; i < n; i++)
        {
            need[i] = nums[i];
            vis[i] = false;
        }
        for (int i = 0; i < m; i++)
        {
            last[changeIndices[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            if (last.find(i) == last.end())
            {
                return -1;
            }
        }

        int k = 0, cnt = 0;

        while (k < m)
        {
            if (nums[changeIndices[k]] == 0 && vis[changeIndices[k]] == false)
            {
                k++;
                cnt++;
                vis[changeIndices[k]] = true;
                if (cnt == n)
                {
                    return k;
                }
                continue;
            }
            int extra = INT_MAX, index = 0;
            for (int i = 0; i < n; i++)
            {
                if(need[i] == 0) continue; 
                int temp = last[i] - k - need[i];
                if(temp < 0) return -1;
                if (temp < extra)
                {
                    extra = temp;
                    index = i;
                }
            }
            nums[index]--;
            need[index]--;
            k++;
        }

        return -1;
    }
};
