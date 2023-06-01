// Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
// The union of two arrays can be defined as the common and distinct elements in the two arrays.NOTE: Elements in the union should be in ascending order.

#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    int i = 0, j = 0; // pointers

    vector<int> Union; // Union vector

    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
            {
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
        {
            Union.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }

    // print Union Vector
    for (int i = 0; i < Union.size(); i++)
    {
        cout << Union[i] << " ";
    }

    return 0;
}
