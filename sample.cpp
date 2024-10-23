#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int n = bank.size();
        int m = bank[0].size();
        int ans = 0, prev = 0;
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = 0; j < m; j++)
            {
                if(bank[i][j] == '1')
                {
                    temp++;
                    ans += prev;
                }
            }
            if(temp != 0)   prev = temp;
            
        }
        return ans;
    }
};
