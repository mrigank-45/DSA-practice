// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) 
// of size K.
// Input : N = 5 || A[] = {-8, 2, 3, -6, 10} || K = 2
// Output : -8 0 -6 -6

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    int negative = -1;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    for (int i = K; i < N; i++)
    {

        if (!dq.empty() && (i - dq.front()) >= K)
        {
            dq.pop_front();
        }

        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{

    long long int arr[8] = {-8, 2, 3, -6, 10};
    long long int k = 2;

    vector<long long> ans = printFirstNegativeInteger(arr, 5, k);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}
