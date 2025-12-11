// Number of Inversions (codestudio)
// Use Merge sort with the adjustment that whenever an unsorted pair is discovered, increase the count by one and return the count at the end.

#include <bits/stdc++.h>
using namespace std;

int modifiedMerge(vector<int>& a, vector<int>& temp, int start, int mid, int end)
{
    int inversionCount = 0;

    int i = start, j = mid, k = start;

    while ((i <= mid - 1) and (j <= end)) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            k++, i++;
        }
        else
        {
            temp[k] = a[j];
            k++, j++;

            // Increase the inversion count by 'mid'-i as all
            // elements from 'A[i]' to 'A[mid]' are greater
            // then A[j].
            inversionCount = inversionCount + (mid - i);
        }
    }

    // Copy rest of the left half elements.
    while (i <= mid - 1) {
        temp[k] = a[i];
        k++, i++;
    }

    // Copy rest of the right half elements.
    while (j <= end) {
        temp[k] = a[j];
        k++, j++;
    }

    // Update the elements of array 'A'.
    for (i = start ; i <= end ; i++)
        a[i] = temp[i];

    // Return the 'inversionCount'.
    return inversionCount;
}

int modifiedMergeSort(vector<int>& a, vector<int>& temp, int start, int end)
{
    int mid, inversionCount = 0;
    if (end > start)
    {
        mid = (start + end) / 2;

        inversionCount += modifiedMergeSort(a, temp, start, mid);

        inversionCount += modifiedMergeSort(a, temp, mid + 1, end);

        // Merge both the halves and count the number of inversions.
        inversionCount += modifiedMerge(a, temp, start, mid + 1, end);
    }

    return inversionCount;
}

int numberOfInversions(vector<int>&a, int n) {

    int answer = 0;
    vector<int>temp(n); // created to simple store the sorted array temporarily

    answer = modifiedMergeSort(a, temp, 0, n - 1);

    return answer;
}
