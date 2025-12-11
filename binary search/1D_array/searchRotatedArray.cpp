// Q1: Find the pivot element in an rotated array.
// Idea is that it is the minimum element in the array
// Q2: Search an element in an rotated array
// Idea is that we alredy so the pivot element so we know in which part of 
// rotated array we need to apply binary search.

#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &arr, int n)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int key)
{

    int start = s;
    int end = e;

    int mid = start + (end - start) / 2;

    while (start <= end)
    {

        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right wala part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        { // key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    return -1;
}

int searchPosition(vector<int> &arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    { // BS on second line
        return binarySearch(arr, pivot, n - 1, k);
    }
    else
    { // BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main()
{
    vector<int> v = {6, 10, 2, 3, 4};
    cout << "Pivot is " << getPivot(v, 5) << endl;
    cout << "Position of 3 is " << searchPosition(v,5, 3) << endl;
}
