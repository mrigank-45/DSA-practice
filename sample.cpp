#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int find_peak(vector<int> v)
    // {
    //     int s = 0, e = v.size() - 1;
    //     int mid = (s + e) / 2;
    //     while (s < e)
    //     {
    //         if (mid == s)
    //         {
    //             if (v[mid] > v[mid + 1])
    //             {
    //                 return mid;
    //             }
    //             else
    //             {
    //                 return mid + 1;
    //             }
    //         }
    //         else if (v[mid] > v[mid - 1])
    //         {
    //             s = mid;
    //         }
    //         else
    //         {
    //             e = mid - 1;
    //         }

    //         mid = (s + e) / 2;
    //     }
    //     return e;
    // }

    vector<int> findPeakElement(vector<int> nums)
    {

        if (nums.size() == 1)
            return {0};

        vector<int> peaks;

        findPeak(0, nums.size(), nums, peaks);

        return peaks;
    }

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

    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {

        int row = arr.size();
        int col = arr[0].size();

        for (int i = 0; i < row; i++)
        {
            vector<int> peaks = findPeakElement(arr[i]);
            for (int j = 0; j < peaks.size(); j++)
            {
                if (i == 0)
                {
                    if (arr[i][peaks[j]] >= arr[i + 1][peaks[j]])
                    {
                        return {i, peaks[j]};
                    }
                }
                else if (i == row - 1)
                {
                    if (arr[i][peaks[j]] >= arr[i - 1][peaks[j]])
                    {
                        return {i, peaks[j]};
                    }
                }
                else
                {
                    if (arr[i][peaks[j]] >= arr[i - 1][peaks[j]] && arr[i][peaks[j]] >= arr[i + 1][peaks[j]])
                    {
                        return {i, peaks[j]};
                    }
                }
            }
        }
        return {0, 0};
    }
};
