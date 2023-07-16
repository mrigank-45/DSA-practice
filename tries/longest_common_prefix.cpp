// Write a function to find the longest common prefix string amongst an array of strings.
// We will solve using tries to understand the concept of tries
// ALGO: Start from root and move till the node has only one child and keep updating the ans.

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    // Insertion function
    void insertUtil(TrieNode *curr, string word)
    {
        if (word.length() == 0)
        {
            curr->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (curr->children[index] != NULL)
        {
            child = curr->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            curr->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    // Longest Common Prefix function
    string lcp()
    {
        TrieNode *curr = root;
        string ans = "";

        while (curr && !curr->isTerminal && countChildren(curr) == 1)
        {
            // finding the child node so that we can move to the next node
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != NULL)
                {
                    ans.push_back('a' + i);
                    curr = curr->children[i];
                    break;
                }
            }
        }

        return ans;
    }

    int countChildren(TrieNode *node)  // counts the children of a node
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // Step 1: Insert all the strings into the Trie
        Trie t;
        for (string &str : strs)
        {
            t.insertWord(str);
        }

        // Step 2: Find the longest common prefix
        return t.lcp();
    }
};
