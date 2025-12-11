// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]   Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRow(vector<vector<int>> &mat, int col, int m, int n)
    {
        int maxi = -1;
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (mat[i][col] > maxi)
            {
                maxi = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();    // rows
        int m = mat[0].size(); // columns

        int low = 0, high = m - 1;

        while (low <= high)
        {
            int midcol = low + (high - low) / 2;
            int midrow = findRow(mat, midcol, m, n); // find max element of that column

            // Ensure that left and right are not out of bounds
            int left = midcol - 1 >= low ? mat[midrow][midcol - 1] : -1;
            int right = midcol < high ? mat[midrow][midcol + 1] : -1;

            if (mat[midrow][midcol] > left && mat[midrow][midcol] > right)
            {
                return {midrow, midcol};
            }
            else if (mat[midrow][midcol] < left)
            {
                high = midcol - 1;
            }
            else
            {
                low = midcol + 1;
            }
        }
        return {-1, -1};
    }
};
