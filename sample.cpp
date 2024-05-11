#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {

        int n = gas.size();

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            if(gas[i] >= cost[i])
            {
                v.push_back(i);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            int j = v[i];
            int sum = 0;
            int k = 0;
            while (k < n)
            {
                sum += gas[j] - cost[j];
                if (sum < 0)
                {
                    break;
                }
                j++;
                if (j == n)
                {
                    j = 0;
                }
                k++;
            }
            if (k == n)
            {
                return v[i];
            }
        }

        return -1;
    }
};
