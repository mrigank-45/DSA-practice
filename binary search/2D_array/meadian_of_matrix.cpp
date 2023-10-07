// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.
// M = [[1, 3, 5],
//      [2, 6, 9],
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.

#include <bits/stdc++.h>
using namespace std;

int countSmallerThanOrEqualToMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) // finding max and min of matrix
    {
        if (A[i][0] < low)
        {
            low = A[i][0];
        }

        if (A[i][m - 1] > high)
        {
            high = A[i][m - 1];
        }
    }

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanOrEqualToMid(A[i], mid);
        }
        if (cnt <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int row = 3, col = 3;
    vector<vector<int>> arr = {{1, 3, 8},
                               {2, 4, 5},
                               {1, 2, 5}};
    cout << "The median of the row-wise sorted matrix is: " << findMedian(arr) << endl;
    return 0;
}
