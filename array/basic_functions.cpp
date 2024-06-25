#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3] = {5, 1, 2};

    swap(arr[0], arr[1]);
    reverse(arr, arr + 3);

    // next_permutation returns true if arr can rearrange as a lexicographically greater permutation, else false
    do
    {
        // will return false when arr = {5, 2, 1}
        cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
    } while (next_permutation(arr, arr + 3));
    // similarly prev_permutation(arr, arr + 3)

    sort(arr, arr + 3);

    return 0;
}
