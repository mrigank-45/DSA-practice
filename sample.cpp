#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        int n = logs.size();
        sort(logs.begin(),logs.end());
        vector<int> ans(k, 0);

        int id = logs[0][0];
        int curr = 1;

        for(int i = 1; i<n; i++){
            if(logs[i][0] == logs[i-1][0] && logs[i][1] == logs[i-1][1]){
                continue;
            }
            if(logs[i][0] == id){
                curr++;
            }
            else{
                ans[curr - 1]++;
                id = logs[i][0];
                curr = 1;
            }
        }
        ans[curr - 1]++;
        return ans;
    }
};
