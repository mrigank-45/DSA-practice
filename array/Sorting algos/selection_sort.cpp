#include <bits/stdc++.h>
using namespace std;

// For i = 0 till i<n-1, find the minimum element in the array from (i+1) to (n-1) and swap it with the element at i.
// TC: O(n^2)

void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
