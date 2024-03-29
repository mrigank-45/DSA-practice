// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes
// the number of aggressive cows. You are given the task of assigning stalls to k cows (k<=n) such that the minimum distance between any
// two of them is the maximum possible.

// Input: n=5, k=3, stalls = [1 2 4 8 9] || Output: 3
// Explanation:
// The first cow can be placed at stalls[0],
// the second cow can be placed at stalls[2] and
// the third cow can be placed at stalls[3].
// The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid, int n)
{

    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < n; i++)
    {

        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int n = stalls.size();
    int e = stalls[n - 1];
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid, n))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 6, 2, 10};

    int ans = aggressiveCows(arr, 3);
    cout << ans << endl;
}
