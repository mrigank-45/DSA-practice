#include <bits/stdc++.h>
using namespace std;

// compare function is needed as first we want to process the element which has less operation till now in queue{x, op};
struct ComparePairs
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) const
    {

        return p1.second > p2.second;
    }
};

class Solution
{
public:
    int minimumOperationsToMakeEqual(int x, int y)
    {

        if (x < y)
        {
            return y - x;
        }

        pair<int, int> p;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> q;

        q.push({x, 0});
        int curr, op;
        int mod11, mod5, inv11, inv5, div11, div5;

        while (!q.empty())
        {
            p = q.top();
            q.pop();
            curr = p.first;
            op = p.second;

            if (curr == y)
                return op;

            if (curr % 11 == 0)
                q.push({curr / 11, op + 1});

            if (curr % 5 == 0)
                q.push({curr / 5, op + 1});

            if (curr < y)
                q.push({y, op + y - curr});

            if (curr > y)
            {
                mod11 = curr % 11;
                mod5 = curr % 5;
                inv11 = 11 - mod11;
                inv5 = 5 - mod5;

                div11 = curr / 11;
                div5 = curr / 5;

                q.push({div11, op + mod11 + 1});
                q.push({div5, op + mod5 + 1});
                q.push({div11 + 1, op + inv11 + 1});
                q.push({div5 + 1, op + inv5 + 1});
            }

            if (curr > y)
                q.push({curr - 1, op + 1});
        }

        return 0;
    }
};
