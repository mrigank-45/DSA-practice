// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list,
// or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the
// value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list
// such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in
// the copied list, x.random --> y. Return the head of the copied linked list.

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int data)
    {
        next = NULL;
        this->val = val;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class Solution
{
public:
    Node *copyList(Node *head)
    {
        map<Node *, Node *> m;
        Node *cursor = head;
        while (cursor !=NULL)
        {
            Node *temp = new Node(cursor->val);
            m[cursor] = temp;
            cursor = cursor->next;
        }
        cursor = head;
        while (cursor !=NULL)
        {
            if (cursor->next != NULL)
                m[cursor]->next = m[cursor->next];
            if (cursor->random != NULL)
                m[cursor]->random = m[cursor->random];
            cursor = cursor->next;
        }

        return m[head];
    }
};
