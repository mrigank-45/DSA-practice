// A peak element is an element that is strictly greater than its neighbors.
// Input: nums = [1,2,3,1]
// Output: 2
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Given that the input array will be in this form only

#include <bits/stdc++.h>
using namespace std;

int find_peak(vector<int> v)
{
    int s = 0, e = v.size() - 1;
    int mid = (s + e) / 2;
    while (s < e)
    {
        if (v[mid] < v[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = (s + e) / 2;
    }
    return s;
}

int main()
{
    vector<int> v = {1,1,1,1,1,2,4};

    int ans = find_peak(v);

    cout << v[ans] << endl;
}
