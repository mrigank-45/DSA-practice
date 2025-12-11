#include <bits/stdc++.h>
using namespace std;

void findPeak(int start, int end, vector<int> nums, vector<int> peaks)
{
    if (start > end || start == nums.size() || end < 0)
        return;

    int middle = start + (end - start) / 2;

    if (middle == 0)
    {
        if (nums[start] > nums[start + 1])
        {
            peaks.push_back(0);
        }
        else
        {
            findPeak(1, 1, nums, peaks);
        }
    }
    else if (middle == nums.size() - 1)
    {
        if (nums[middle] > nums[middle - 1])
        {
            peaks.push_back(middle);
        }
    }
    else
    {
        if (nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1])
        {
            peaks.push_back(middle);
        }
    }

    findPeak(middle + 1, end, nums, peaks);
    findPeak(start, middle - 1, nums, peaks);
}

vector<int> findPeakElements(vector<int> nums)
{

    if (nums.size() == 1)
        return {0};

    vector<int> peaks;

    findPeak(0, nums.size(), nums, peaks);

    return peaks;
}
