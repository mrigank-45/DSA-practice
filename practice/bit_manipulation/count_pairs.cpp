// count-pairs-of-points-with-distance-k (leetocde)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<vector<int>> &c, int k)
    {

        // finding all possible (x,y) which gives :
        // c[i][0]^x+c[i][1]^y=k                   (0)
        // Consider above is true , then
        // if , c[i][0]^x=val                      (1)
        // then c[i][1]^y=k-val                    (2)

        // We can definitely find all possible values of val (0 to k inclusive)
        // using a^b=c , then a^c=b
        // from  (1) , we have c[i][0]^val=x;
        // from  (2) , we have c[i][1]^(k-val)=y;
        // so we just need to traverse through all possible values of val to get pairs(x,y) satisfying  eq.(0)

        int n = c.size();
        // to keep track which pair of (x,y) is visited
        map<pair<int, int>, int> hash;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x1 = c[i][0];
            int y1 = c[i][1];
            for (int i = 0; i <= k; i++)
            {
                int x2 = i ^ x1;
                int y2 = (k - i) ^ y1;
                // increase count if (x2,y2) is already visited
                cnt = cnt + hash[{x2, y2}];
            }

            hash[{x1, y1}]++;
        }
        return cnt;
    };
};
