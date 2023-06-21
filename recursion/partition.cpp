// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int low, int high)
{
    while (low < high)
    {
        if (s[low++] != s[high--])
            return false;
    }
    return true;
}

void solve(vector<vector<string>> &result, string &s, int start, vector<string> &currentList)
{
    if (start >= s.length())
        result.push_back(currentList);
    for (int end = start; end < s.length(); end++)
    {
        if (isPalindrome(s, start, end))
        {
            // add current substring in the currentList
            currentList.push_back(s.substr(start, end - start + 1));
            solve(result, s, end + 1, currentList);
            // backtrack and remove the current substring from currentList
            currentList.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> currentList;
    solve(result, s, 0, currentList);
    return result;
}

int main()
{

    vector<vector<string>> s = partition("abbab");
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}
