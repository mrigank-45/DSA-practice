#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) || SC: O(n)
// It is a stable sort algo, which means it maintains the relative order of equal elements in the input array.

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    // copy values
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k];
        k++;
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    k = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[k] = first[index1];
            k++;
            index1++;
        }
        else
        {
            arr[k] = second[index2];
            k++;
            index2++;
        }
    }

    while (index1 < len1)
    {
        arr[k] = first[index1];
        k++;
        index1++;
    }

    while (index2 < len2)
    {
        arr[k] = second[index2];
        k++;
        index2++;
    }
}

void mergeSort(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}
