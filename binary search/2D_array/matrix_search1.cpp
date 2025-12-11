// Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order, and a number X is given. 
// The task is to find whether element X is present in the matrix or not.

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int start = 0;
    int end = row * col - 1;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        int element = matrix[mid / col][mid % col];

        if (element == target)
        {
            return 1;
        }

        if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}

int main()
{

    vector<vector<int>> matrix = {{2, 4, 6},
                                  {12, 16, 19},
                                  {23, 35, 67}};

    cout << searchMatrix(matrix, 19);

    return 0;
}
