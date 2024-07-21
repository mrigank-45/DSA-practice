#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int n = happiness.size();

        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push(happiness[i]);
        }

        int decrement = 0;
        long long sum = 0;

        while (k > 0)
        {
            int top = pq.top();
            pq.pop();
            top -= decrement;
            if (top > 0)
            {
                sum += top;
            }
            decrement++;
            k--;
        }

        return sum;
    }
};
