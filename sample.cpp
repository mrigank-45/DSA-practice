#include <bits/stdc++.h>
using namespace std;

class MountainArray
{
public:
    int get(int index);
    int length();
};

class Solution
{
public:
    int peakIndexInMountainArray(MountainArray &arr)
    {
        int n = arr.length();
        int start = 0, end = n - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) < arr.get(mid + 1))
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        return start;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();
        int peak = peakIndexInMountainArray(mountainArr);
        if(mountainArr.get(peak) == target) return peak;
        if(target > mountainArr.get(peak)) return -1;
        int start = 0, end = peak;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        start = peak, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target)
            {
                return mid;
            }
            else if (mountainArr.get(mid) < target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};
