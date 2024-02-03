#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        int n = processorTime.size();

        sort(processorTime.begin(), processorTime.end());

        priority_queue<int> pq; // max heap for tasks

        priority_queue<int> ans; // max heap for ans

        for (int i = 0; i < tasks.size(); i++)
        {
            pq.push(tasks[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                ans.push(processorTime[i] + pq.top());
                pq.pop();
            }
        }

        return ans.top();
    }
};
