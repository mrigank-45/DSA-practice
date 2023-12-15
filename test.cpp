#include <bits/stdc++.h>
using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }
        return hash1;
    }
};
class Solution
{
public:
    long long solve(vector<int> &nums, int modulo, int k, long long int cnt, long long int &ans, long long int i, long long int j, unordered_map<pair<int, int>, bool, hash_pair> m)
    {
        if (cnt % modulo == k)
        {
            ans++;
            cout << i << " " << j << endl;
            cout << "cnt: " << cnt << endl;
            cout << "ans: " << ans << endl;
        }

        if (i + 1 < nums.size() && i + 1 <= j && !m[{i + 1, j}])
        {
            if (nums[i] % modulo == k)
            {
                m[{i + 1, j}] = true;
                cnt--;
                solve(nums, modulo, k, cnt, ans, i + 1, j, m);
            }
            else
            {
                m[{i + 1, j}] = true;
                solve(nums, modulo, k, cnt, ans, i + 1, j, m);
            }
        }

        if (j - 1 >= 0 && i <= j - 1 && !m[{i, j - 1}])
        {
            if (nums[j] % modulo == k)
            {
                m[{i, j - 1}] = true;
                cnt--;
                solve(nums, modulo, k, cnt, ans, i, j - 1, m);
            }
            else
            {
                m[{i, j - 1}] = true;
                solve(nums, modulo, k, cnt, ans, i, j - 1, m);
            }
        }

        return ans;
    }
    long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
    {
        long long int cnt = 0, ans = 0;

        unordered_map<pair<int, int>, bool, hash_pair> m;

        for (long long int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % modulo == k)
            {
                cnt++;
            }
        }

        solve(nums, modulo, k, cnt, ans, 0, nums.size() - 1, m);

        return ans;
    }
};
