#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> s(dictionary.begin(), dictionary.end());
        string ans;

        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
                continue;

            string word = "";
            while (i < sentence.size() && sentence[i] != ' ')
            {
                word += sentence[i];
                i++;
            }

            for (int j = 1; j <= word.size(); j++)
            {
                if (s.find(word.substr(0, j)) != s.end())
                {
                    word = word.substr(0, j);
                    break;
                }
            }
            ans += word + " ";
        }
        if (!ans.empty())
            ans.pop_back(); 
        return ans;
    }
};
