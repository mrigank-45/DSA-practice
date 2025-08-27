#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        int flag = 0, curr = 0, ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (flag == 0)
            {
                if (arr[i] < arr[i + 1])
                {
                    curr = 2;
                    flag = 1;
                }
            }
            else if (flag == 1)
            {
                if (arr[i] < arr[i + 1])
                {
                    curr++;
                }
                else if (arr[i] > arr[i + 1])
                {
                    curr++;
                    flag = 2;
                    ans = max(ans, curr);
                }
                else
                {
                    curr = 0;
                    flag = 0;
                }
            }
            else if (flag == 2)
            {
                if(arr[i] > arr[i + 1])
                {
                    curr++;
                    ans = max(ans, curr);
                }
                else if (arr[i] < arr[i + 1])
                {
                    curr = 2;
                    flag = 1;
                }
                else
                {
                    curr = 0;
                    flag = 0;
                }

            }
        }
        return ans;
    }
};
