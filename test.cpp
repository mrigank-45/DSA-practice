#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int mid, int n)
{
    int ans = 0;
    unordered_map<int, int> mp;
    int i = 0;
    int j = 0;
    while (j < n)
    {
        mp[nums[j]]++;
        while (i <= j && mp.size() > mid)
        {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0)
            {
                mp.erase(nums[i]);
            }
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int n = nums.size();
    cout << helper(nums, 1, n) << endl;
    cout << helper(nums, 2, n) << endl;

    cout << helper(nums, 3, n) << endl;
}
