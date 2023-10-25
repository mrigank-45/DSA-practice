#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &arr)
    {
        long long n = arr.size(), i;
        vector<long long> nsr(n, n + 1), nsl(n, -1); // we will be storing indices
        stack<long long> st1, st2;

        // Finding NSR
        st1.push(n - 1);
        for (i = n - 2; i >= 0; i--)
        {
            while (!st1.empty() && arr[st1.top()] >= arr[i])
                st1.pop();
            if (!st1.empty())
                nsr[i] = st1.top();
            st1.push(i);
        }
        // Finding NSL
        st2.push(0);
        for (i = 1; i < n; i++)
        {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            if (!st2.empty())
                nsl[i] = st2.top();
            st2.push(i);
        }

        vector<long long> hr(n, 0), hl(n, 0);
        // height of beautiful tower to the right
        hr[n - 1] = arr[n - 1];
        for (i = n - 2; i >= 0; i--)
        {
            if (nsr[i] == n + 1) // no smaller element to the right
            {
                hr[i] = arr[i] * (n - i);
            }
            else
            {
                hr[i] = arr[i] * (nsr[i] - i) + hr[nsr[i]];
            }
        }
        // height of beautiful tower to the left
        hl[0] = arr[0];
        for (i = 1; i < n; i++)
        {
            if (nsl[i] == -1) // no smaller element to the left
            {
                hl[i] = arr[i] * (i + 1);
            }
            else
            {
                hl[i] = arr[i] * (i - nsl[i]) + hl[nsl[i]];
            }
        }
        long long res = 0;
        for (i = 0; i < n; i++)
        {
            res = max(res, hl[i] + hr[i] - arr[i]); // arr[i] is counted twice so subhracting it once
        }

        return res;
    }
};
