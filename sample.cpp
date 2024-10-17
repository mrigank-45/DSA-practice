#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size(), targetArrival = times[targetFriend][0];

        sort(times.begin(), times.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++)
        {
            available.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeTime; // (ending time, room number)

        for (auto &meet : times)
        {
            int room;
            while (!freeTime.empty() && freeTime.top().first <= meet[0])
            {
                room = freeTime.top().second;
                available.push(room);
                freeTime.pop();
            }
            room = available.top();
            available.pop();
            if (meet[0] == targetArrival)
            {
                return room;
            }
            freeTime.push({meet[1], room});
        }

        return 0;
    }
};
