// Given an array of integers arr[] and an integer target.
// Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
// 2 pointer approach

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;

    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            cout << arr[left] << " " << arr[right] << endl;
            break;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return 0;
}
