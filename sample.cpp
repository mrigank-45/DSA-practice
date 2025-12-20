#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNextRideIndex(vector<vector<int>>& rides, int endPoint) {
        int l = 0, r = rides.size() - 1;
        int ans = rides.size();
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (rides[mid][0] >= endPoint) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    long long solve(vector<vector<int>>& rides, int i, vector<long long>& dp) {
        if (i >= rides.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        long long notPick = solve(rides, i + 1, dp);

        int nextIndex = getNextRideIndex(rides, rides[i][1]);
        long long profit = (long long)(rides[i][1] - rides[i][0] + rides[i][2]);
        long long pick = profit + solve(rides, nextIndex, dp);

        return dp[i] = max(pick, notPick);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size(), -1);
        return solve(rides, 0, dp);
    }
};
