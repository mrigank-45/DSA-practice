#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        long long sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            pq.push({nums[i], i});
        }
        map<int, bool> mp;
        vector<long long> answer;

        for (int i = 0; i < queries.size(); i++)
        {
            int index = queries[i][0];
            int k = queries[i][1];

            if (!mp[index])
            {
                sum -= nums[index];
                mp[index] = true;
            }

            while (!pq.empty() && k > 0)
            {
                if (mp[pq.top().second])
                {
                    pq.pop();
                    continue;
                }
                else
                {
                    sum -= pq.top().first;
                    mp[pq.top().second] = true;
                    pq.pop();
                    k--;
                }
            }
            answer.push_back(sum);
        }

        return answer;
    }
};
