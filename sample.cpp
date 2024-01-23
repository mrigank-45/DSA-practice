#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];

    TrieNode()
    {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};
class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *current = root;
        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            if (!current->children[bit])
            {
                current->children[bit] = new TrieNode();
            }
            current = current->children[bit];
        }
    }

    int solve(int num)
    {
        TrieNode *current = root;
        int maxXOR = 0;

        for (int i = 31; i >= 0; --i)
        {
            int bit = (num >> i) & 1;
            int flipBit = 1 - bit;

            if (current->children[flipBit])
            {
                maxXOR |= (1 << i);
                current = current->children[flipBit];
            }
            else
            {
                current = current->children[bit];
            }
        }

        return maxXOR;
    }
};

int find_max_xor(int lo, int hi, int k)
{
    Trie trie;
    int max_xor = 0;

    for (int i = lo; i <= hi; ++i)
    {
        trie.insert(i);
        int complement = k - i;
        max_xor = max(max_xor, trie.solve(complement));
    }

    return max_xor;
}

int main()
{
    int lo = 3;
    int hi = 5;
    int k = 6;

    int max_xor = find_max_xor(lo, hi, k);

    cout << "The maximum XOR value is " << max_xor << endl;

    return 0;
}
