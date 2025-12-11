// Number of Black Blocks

#include <bits/stdc++.h>
using namespace std;

// Algo explanation: https://leetcode.com/problems/number-of-black-blocks/solutions/3739444/c-map-counting-easy-to-understand/ 
class Solution
{
public:
    vector<pair<int, int>> move // direction vector
        {
            {-1, 0}, {0, -1}, {-1, -1} // left top top-left
        };

    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> &coordi)
    {
        map<pair<int, int>, long long> mp; // map to store count of black cell in block starting at cordinate x and y
        for (auto it : coordi)
        {
            int a = it[0];
            int b = it[1];
            bool add = 1;
            if (a < 0 || b < 0 || a >= m - 1 || b >= n - 1) // checking if  we can form 2x2 block at row a and col b
                add = 0;
            if (add) // if we can form we will increase count of black cells
                mp[{a, b}]++;
            for (auto it2 : move)
            {
                int x = it2.first + it[0];
                int y = it2.second + it[1];

                if (x < 0 || y < 0 || x >= m - 1 || y >= n - 1) // if x and y are valid
                    continue;
                mp[{x, y}]++; // increase count of black cells
            }
        }
        vector<long long> v(5, 0);
        for (auto it : mp)
        {

            if (it.second == 1)
                v[1]++;
            else if (it.second == 2)
                v[2]++;
            else if (it.second == 3)
                v[3]++;
            else if (it.second == 4)
                v[4]++;
        }
        long long tot = m - 1;
        tot *= (n - 1);
        // cout<<tot<<endl;
        tot -= mp.size();
        v[0] = tot; // count of blocks having 0 black cells
        return v;
    }
};
