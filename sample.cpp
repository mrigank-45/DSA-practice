#include <bits/stdc++.h>
using namespace std;

class Router
{
public:
    struct custom_hash
    {
        size_t operator()(const pair<int, pair<int, int>> &p) const
        {
            return hash<int>()(p.first) ^ hash<int>()(p.second.first) ^ hash<int>()(p.second.second);
        }
    };
    deque<pair<int, pair<int, int>>> q; // {source, {destination, timestamp}}
    unordered_set<pair<int, pair<int, int>>, custom_hash> s;
    int memoryLimit;
    Router(int memoryLimit)
    {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp)
    {
        if (s.find({source, {destination, timestamp}}) != s.end())
        {
            return false;
        }

        if (q.size() == memoryLimit)
        {
            auto oldestPacket = q.front();
            s.erase({oldestPacket.first, {oldestPacket.second.first, oldestPacket.second.second}});
            q.pop_front();
        }

        q.push_back({source, {destination, timestamp}});
        s.insert({source, {destination, timestamp}});
        return true;
    }

    vector<int> forwardPacket()
    {
        if (q.empty())
        {
            return {};
        }
        vector<int> result = {q.front().first, q.front().second.first, q.front().second.second};
        s.erase({q.front().first, {q.front().second.first, q.front().second.second}});
        q.pop_front();
        return result;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        int cnt = 0;
        for (auto &packet : s)
        {
            if (packet.second.first == destination && packet.second.second >= startTime && packet.second.second <= endTime)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
