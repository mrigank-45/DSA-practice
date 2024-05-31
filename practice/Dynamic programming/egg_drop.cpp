#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memorization
    int find(int k, int n, vector<vector<int>> &memo)
    {
        if (n == 0 || n == 1)
            return n; // if no. of floor 0 , 1 return n:
        if (k == 1)
            return n; // if 1 egg return number of floor
        if (memo[k][n] != -1)
            return memo[k][n];
        int ans = 1000000, l = 1, h = n, temp = 0;

        while (l <= h)
        {
            int mid = (l + h) / 2;
            int left = find(k - 1, mid - 1, memo); // egg broken check for down floors of mid
            int right = find(k, n - mid, memo);    // not broken check for up floors of mid
            temp = 1 + max(left, right);           // store max of both
            if (left < right)
            {                // since right is more than left and we need more in worst case
                l = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
            }
            else // left > right so we will go downward
            {
                h = mid - 1;
            }
            ans = min(ans, temp); // store minimum attempts
        }

        /*
           Here we have k eggs and n floor
           if we drop from i  (i=1 to n):
            i) egg break , now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will also break
           ii) egg not break , now we remain k eggs and n-i floor because before i (included) all eggs will be remain
         */
        return memo[k][n] = ans;
    }

    int tabulation(int K, int N)
    {
        if (N == 0 || N == 1)
            return N; // Think for base case
        if (K == 1)
            return N;

        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        for (int i = 0; i <= K; i++)
            dp[i][0] = 0, dp[i][1] = 1; // Filling from base case as if N==0 ans=0 , N==1 ans=1
        for (int i = 0; i <= N; i++)
            dp[0][i] = 0, dp[1][i] = i; // Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)

        for (int i = 2; i < K + 1; i++)
        {
            for (int j = 2; j < N + 1; j++)
            {
                int l = 1, h = j, temp = 0, ans = 100000;
                while (l <= h)
                {
                    int mid = (l + h) / 2;
                    int left = dp[i - 1][mid - 1]; // egg broken check for down floors of mid
                    int right = dp[i][j - mid];    // not broken check for up floors of mid
                    temp = 1 + max(left, right);   // store max of both
                    if (left < right)
                    {                // since right is more than left and we need more in worst case
                        l = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else // left > right so we will go downward
                    {
                        h = mid - 1;
                    }
                    ans = min(ans, temp); // store minimum attempts
                }
                dp[i][j] = ans;
            }
        }
        return dp[K][N];
    }

    int superEggDrop(int K, int N)
    {
        // K -> egg , N -> floor
        vector<vector<int>> memo(K + 1, vector<int>(N + 1, -1));
        return find(K, N, memo);
    }
};
