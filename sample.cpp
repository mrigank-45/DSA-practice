#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int n, unordered_map<int, pair<int, int>> &mp, int i, vector<int> &sum)
    {
        if (mp[i].first == -1 && mp[i].second == -1)
        {
            sum[i] = 1;
            return 1;
        }
        int ans = 1;
        if(mp[i].first != -1)
        {
            ans += dfs(n, mp, mp[i].first, sum);
        }
        if(mp[i].second != -1)
        {
            ans += dfs(n, mp, mp[i].second, sum);
        }
        sum[i] = ans;
        return ans;
    }
    int countHighestScoreNodes(vector<int> &parents)
    {
        int n = parents.size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
            mp[i] = {-1, -1};

        for (int i = 1; i < n; i++)
        {
            if (mp[parents[i]].first == -1)
            {
                mp[parents[i]].first = i;
            }
            else
            {
                mp[parents[i]].second = i;
            }
        }
        vector<int> sum(n, -1);
        sum[0] = dfs(n, mp, 0, sum);

        long long maxi = 0;
        vector<long long> res(n, -1);
        for(int i =0; i<n;i++){
            long long score = 1;
            if(mp[i].first != -1){
                score *= sum[mp[i].first];
            }
            if(mp[i].second != -1){
                score *= sum[mp[i].second];
            }
            if(i!=0){
                score *= (n-sum[i]);
            }
            res[i] = score;
            maxi = max(maxi,score);
        }
        int ans = 0;
        for(int i=0; i<n;i++){
            if(res[i] == maxi){
                ans++;
            }
        }
        return ans;
    }
};
