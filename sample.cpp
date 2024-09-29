#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> anagramMap;
    vector<string> order;
    vector<string> ans;

    // Create a copy of the original array
    vector<string> original = strs;

    // Sort the strings and populate the unordered map
    for (const string &str : original)
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());

        // If this sorted string is encountered for the first time
        if (anagramMap.find(sortedStr) == anagramMap.end())
        {
            order.push_back(sortedStr); // Track the first occurrence for order
        }
        anagramMap[sortedStr].push_back(str);
    }

    // Build the final answer array
    for (const string &firstStr : order)
    {
        // Push the grouped anagrams in original order
        for (const string &groupedStr : anagramMap[firstStr])
        {
            ans.push_back(groupedStr);
        }
    }

    return ans;
}

int main()
{
    vector<string> strs = {"acb", "cc", "nmn", "bac", "abc", "nnm", "mmn", "cba"};
    vector<string> result = groupAnagrams(strs);

    // Output the result
    for (const string &s : result)
    {
        cout << s << " ";
    }
    return 0;
}
