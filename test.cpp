#include <bits/stdc++.h>
using namespace std;

bool canPush(vector<vector<int>> ans, vector<int> v){
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i]==v)
        {
            return false;
        }
        
    }
    return true;
    
}
void combination(vector<int> &candidates, int target, vector<int> currComb, int currSum, int currIndex, vector<vector<int>>& ans)
{
    if (currSum > target)
    {
        return;
    }
    if (currSum == target)
    {
        
        sort(currComb.begin(),currComb.end());
        if (canPush(ans, currComb))
        {
            ans.push_back(currComb);
        }
        
        cout << endl;

        return;
    }

    for (int i = currIndex +1; i < candidates.size(); i++)
    {
        currComb.push_back(candidates[i]);
        currSum += candidates[i];
        combination(candidates, target, currComb, currSum, i, ans);
        currComb.pop_back();
        currSum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> currComb;
    int currSum = 0;
    int currIndex = -1;
    vector<vector<int>> ans;
    combination(candidates, target, currComb, currSum, currIndex, ans);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    combinationSum(candidates, 7);
}
