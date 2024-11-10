#include <bits/stdc++.h>
using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        vector<pair<int, int>> days;

        for (auto interval : intervals)
        {
            int start = interval.start;
            int end = interval.end;

            bool isInserted = false;
            for (int i = 0; i < days.size(); i++)
            {
                if (days[i].second <= start)
                {
                    days[i].first = start;
                    days[i].second = end;
                    isInserted = true;
                    break;
                }
            }

            if (!isInserted)
            {
                days.push_back({start, end});
            }
        }

        return days.size();
    }
};
