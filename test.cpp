#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rec(int x1, int x2, int y1, int y2, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        if (x1 > x2 || y1 > y2)
            return 0;
        if (x1 == x2 && y1 == y2)
            return 0;


        int min_cost = INT_MAX;

        for (int cut = x1; cut < x2; ++cut)
        {
            int cost = horizontalCut[cut] +
                       rec(x1, cut, y1, y2, horizontalCut, verticalCut) +
                       rec(cut + 1, x2, y1, y2, horizontalCut, verticalCut);
            min_cost = min(min_cost, cost);
        }

        for (int cut = y1; cut < y2; ++cut)
        {
            int cost = verticalCut[cut] +
                       rec(x1, x2, y1, cut, horizontalCut, verticalCut) +
                       rec(x1, x2, cut + 1, y2, horizontalCut, verticalCut);
            min_cost = min(min_cost, cost);
        }

        return min_cost;
    }

    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        return rec(0, m - 1, 0, n - 1, horizontalCut, verticalCut);
    }
};
