#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_peak(vector<int> v)
    {
        int s = 0, e = v.size() - 1;
        int mid = (s + e) / 2;
        while (s < e)
        {
            if (mid == s)
            {
                if (v[mid] > v[mid + 1])
                {
                    return mid;
                }
                else
                {
                    return mid + 1;
                }
            }
            else if (v[mid] > v[mid - 1])
            {
                s = mid;
            }
            else
            {
                e = mid - 1;
            }

            mid = (s + e) / 2;
        }
        return e;
    }

    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {

        int row = arr.size();
        int col = arr[0].size();

        for (int i = 0; i < row; i++)
        {
            int peak = find_peak(arr[i]);
            if (i == 0)
            {
                if (arr[i][peak] >= arr[i + 1][peak])
                {
                    return {i, peak};
                }
            }
            else if (i == row - 1)
            {
                if (arr[i][peak] >= arr[i - 1][peak])
                {
                    return {i, peak};
                }
            }
            else
            {
                if (arr[i][peak] >= arr[i - 1][peak] && arr[i][peak] >= arr[i + 1][peak])
                {
                    return {i, peak};
                }
            }
        }
        return {0, 0};
    }
};
