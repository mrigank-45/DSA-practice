// Count With K Different Characters (codeStudio)
// Given a string and an integer k, find the number of substrings that contain at exactly k distinct characters.
// Sliding window concept

#include <bits/stdc++.h>
using namespace std;

int helper(string str, int k)
{

    int i = 0, j = 0, currCount = 0;
    int result = 0;

    // Array to store count of characters.
    vector<int> count(26, 0);

    while (j < str.size())
    {
        // Index for current character.
        int index = str[j] - 'a';

        // Increment count for the current character.
        count[index] += 1;

        if (count[index] == 1)
        {
            currCount++;
        }

        // Decrement count and increase ith pointer.
        while (currCount > k)
        {
            count[str[i] - 'a']--;
            if (count[str[i] - 'a'] == 0)
            {
                currCount--;
            }

            i++;
        }

        // Total substrings.
        result += (j - i + 1);
        j++;
    }
    return result;
}

int countSubStrings(string str, int k)
{

    // Calculating for at most k and at most k-1 distinct chars.
    int ans = helper(str, k) - helper(str, k - 1);

    return ans;
}
