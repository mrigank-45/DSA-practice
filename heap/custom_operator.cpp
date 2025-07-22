#include <bits/stdc++.h>
using namespace std;

// Custom comparator
struct Compare
{
    bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        // kis case me p1 pehle aayega p2 se
        if (p1.first == p2.first)
        {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};

int main()
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

    pq.push({'a', 0});
    pq.push({'a', 1});
    pq.push({'b', 2});
    pq.push({'b', 1});
    pq.push({'c', 3});

    while (!pq.empty())
    {
        pair<char, int> p = pq.top();
        cout << "{" << p.first << "," << p.second << "}" << endl;
        pq.pop();
    }

    return 0;
}
