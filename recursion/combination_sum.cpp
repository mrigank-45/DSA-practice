// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
// where the chosen numbers sum to target. You may return the combinations in any order. The same number may be chosen from candidates an 
// unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// Input: candidates = [2,3,6,7], target = 7  ||  Output: [[2,2,3],[7]]

#include <bits/stdc++.h>
using namespace std;

void combination(vector<int> &candidates, int target, vector<int> currComb, int currSum, int currIndex)
{
    if (currSum > target)
        return; 
        //  If the sum of the current combination is greater than target, then even if we move forward with this combination, 
        // the sum will only increase, so there is no fun to moving further with such a combination as we can never achieve the target sum from this. 
        // So backtrack from this.
    if (currSum == target)
    {
        for (int i = 0; i < currComb.size(); i++)
        {
            cout << currComb[i] << ' ';
        }
        cout << endl;

        return;
    }

    for (int i = currIndex; i < candidates.size(); i++) // try all possible options for the next level
    {                                      
        currComb.push_back(candidates[i]); // put 1 option into the combination
        currSum += candidates[i];
        combination(candidates, target, currComb, currSum, i); // try with this combination, whether it gives a solution or not.
        currComb.pop_back();                                   // when this option backtrack to here, remove this and go on to the next option.
        currSum -= candidates[i];
    }
}

void combinationSum(vector<int> &candidates, int target)
{
    vector<int> currComb;
    combination(candidates, target, currComb, 0, 0);
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    combinationSum(candidates, 7);
}
