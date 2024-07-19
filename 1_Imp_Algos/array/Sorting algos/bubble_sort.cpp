#include <bits/stdc++.h>
using namespace std;

// for i=1 till i<n, compare the adjacent elements in array from j=0 to j < n-i and swap them if they are in the wrong order.
// TC: O(n^2) (best case is O(n))
// in bubble sort, the largest element goes to its correct position in each iteration.

void bubbleSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i; j++)
        {

            // process element till n-i th index
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
}

// In-place sorting algorithms are those that sort the input array without using any additional memory.
