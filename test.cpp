#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int min_cost = numeric_limits<int>::max();
        vector<int> best_permutation;

        vector<bool> used(n, false);
        vector<int> perm;

        dfs(perm, used, 0, nums, min_cost, best_permutation);
        return best_permutation;
    }

private:
    void dfs(vector<int> &perm, vector<bool> &used, int current_cost, const vector<int> &nums, int &min_cost, vector<int> &best_permutation)
    {
        int n = nums.size();
        if (perm.size() == n)
        {
            int final_cost = current_cost + abs(perm.back() - nums[perm[0]]);
            if (final_cost < min_cost)
            {
                min_cost = final_cost;
                best_permutation = perm;
            }
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                if (!perm.empty())
                {
                    int next_cost = current_cost + abs(perm.back() - nums[i]);
                    if (next_cost < min_cost)
                    {
                        used[i] = true;
                        perm.push_back(i);
                        dfs(perm, used, next_cost, nums, min_cost, best_permutation);
                        perm.pop_back();
                        used[i] = false;
                    }
                }
                else
                {
                    used[i] = true;
                    perm.push_back(i);
                    dfs(perm, used, 0, nums, min_cost, best_permutation);
                    perm.pop_back();
                    used[i] = false;
                }
            }
        }
    }
};
