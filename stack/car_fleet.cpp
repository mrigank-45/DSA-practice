// Car Fleet

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[position[i]] = speed[i];
        }

        sort(position.begin(), position.end());

        stack<float> st;

        for (int i = 0; i < n; i++)
        {
            float time = (target - position[i]) / ((float)mp[position[i]]);

            while (!st.empty() && time >= st.top())
            {
                st.pop();
            }

            st.push(time);
        }

        return st.size();
    }
};
