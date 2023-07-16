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

    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */

    void insertUtil(TrieNode *root, string word)
    {

        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // asumption that all the chracter is in lowercase
        int index = word[0] - 'a';
        TrieNode *child;

        // present -> present h to aage bad  jao
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent ->absent h toh node create karke aage bada do
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursion
        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */

    bool searchUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        // recursion call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            cout << "Word is not present in tries"<<endl;
        }
        // recursion call
        removeUtil(child, word.substr(1));
    }

    void remove(string word)
    {
        removeUtil(root, word);
    }

    bool prefixUtil(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            return true;
        }
        int index = word[0] - 'a'; // make all in small letter
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent
            return false;
        }
        // recursion call
        return prefixUtil(child, word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return prefixUtil(root, prefix);
    }
};
