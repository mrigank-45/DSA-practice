// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could
// be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be
// idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array),
// that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {

        if (n == 0)
            return tasks.size();

        priority_queue<pair<int, char>> pq;
        unordered_map<int, int> freq;

        // Step 1: Store the freq of tasks in a priority queue
        for (int i = 0; i < tasks.size(); i++)
            freq[tasks[i]]++;

        for (auto x : freq)
            pq.push({x.second, x.first});

        int ans = 0;

        // Step 2: Process for each n
        while (pq.size() > 0)
        {
            if (pq.top().first == 1) // indicates last iteration of n
            {
                ans += pq.size();
                break;
            }
            vector<pair<int, char>> v; // to store the elements to push again to priority queue

            for (int i = 0; i < n + 1; i++)
            {
                if (pq.size() > 0)
                {
                    v.push_back(pq.top());
                    pq.pop();
                }
                ans++;
            }

            for (auto x : v) // again push the elements but decrease the freq by one
            {
                if (x.first > 1)
                {
                    pq.push({x.first - 1, x.second});
                }
            }
        }
        return ans;
    }
};
