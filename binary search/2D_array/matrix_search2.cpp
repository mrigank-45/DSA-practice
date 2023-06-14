// Search for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// * Integers in each row are sorted in ascending from left to right.
// * Integers in each column are sorted in ascending from top to bottom.
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target)
{

    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];

        if (element == target)
        {
            return 1;
        }

        if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return 0;
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 5},
                                  {3, 4, 9},
                                  {6, 7, 10}};

    cout << searchMatrix(matrix, 7);

    return 0;
}
