#include <bits/stdc++.h>
using namespace std;

int countSubStrings(string str, int k)
{
    int result = 0;

    // Array to store count of characters.
    vector<int> count(26);

    // All substrings.
    for (int i = 0; i < str.size(); i++)
    {
        int distinctChars = 0;

        // Initializing count array with zero for every iteration.
        fill(count.begin(), count.end(), 0);

        for (int j = i; j < str.length(); j++)
        {

            if (count[str[j] - 'a'] == 0)
            {
                distinctChars++;
            }

            // Increment count of current character.
            count[str[j] - 'a']++;

            if (distinctChars == k)
            {
                result++;
            }
        }
    }

    return result;
}
