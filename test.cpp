#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < flowers.size(); i++)
        {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int x_start;
        int x_end;
        int started = 0;
        int ended = 0;
        for (int j = 0; j < people.size(); j++)
        {
            x_end = lower_bound(end.begin(), end.end(), people[j]) - end.begin() - 1;
            x_start = upper_bound(start.begin(), start.end(), people[j]) - start.begin() - 1;
            people[j] = x_start - x_end;
        }
        return people;
    }
};
