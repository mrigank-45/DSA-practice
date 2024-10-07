#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;

        while (left < right)
        {
            int h = min(height[left], height[right]);
            int w = right - left;
            res = max(res, h * w);
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return res;
    }
};
