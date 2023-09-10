#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> &nums, int idx, vector<int> &temp)
{
    if (idx == nums.size())
    {
        if (temp.size() > ans.size())
            ans = temp;
        return;
    }
    if (temp.size() == 0 || nums[idx] % temp.back() == 0)
    {
        temp.push_back(nums[idx]);
        solve(nums, idx + 1, temp);
        temp.pop_back();
    }
    solve(nums, idx + 1, temp);
}
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    vector<int> temp;
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), -1);
    solve(nums, 0, temp);
    return ans;
}

// int main()
// {

//     vector<int> price = {2, 5, 7, 8, 10};

//     int n = price.size();

//     cout << "The Maximum price generated is " << cutRod(price, n);
// }
