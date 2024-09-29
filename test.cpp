#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagramGroups;

    // Iterate through each string in the original array
    for (const string &str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        bool foundGroup = false;

        // Check existing groups to find a match
        for (auto &group : anagramGroups) {
            string sortedGroupStr = group[0];
            // Sort the first element of the group for comparison
            sort(sortedGroupStr.begin(), sortedGroupStr.end());
            if (sortedStr == sortedGroupStr) {
                group.push_back(str); // Add the original string to this group
                foundGroup = true;
                break;
            }
        }

        // If no matching group found, create a new one
        if (!foundGroup) {
            anagramGroups.push_back({str}); // Start a new group with the original string
        }
    }

    // Flatten the 2D vector into a single vector for the final output
    vector<string> ans;
    for (const auto &group : anagramGroups) {
        for (const string &s : group) {
            ans.push_back(s);
        }
    }

    return ans;
}

int main() {
    vector<string> strs = {"acb", "cc", "nmn", "bac", "abc", "nnm", "mmn", "cba"};
    vector<string> result = groupAnagrams(strs);

    // Output the result
    for (const string &s : result) {
        cout << s << " ";
    }
    return 0;
}
