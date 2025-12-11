#include <bits/stdc++.h>
using namespace std;

// for i=1 to n-1, find the correct position of the element at i in the array from j=i-1 to 0
// TC: O(n^2) (best case is O(n))
// stable algo


void insertionSort(int n, vector<int> &arr)
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        // copy temp value
        arr[j + 1] = temp;
    }
}
