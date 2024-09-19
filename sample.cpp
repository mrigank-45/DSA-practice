#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *root, int left, int right)
    {
        if (!root || left == right)
            return root; // No need to reverse if the list is empty or left == right

        ListNode *dummy = new ListNode(0);
        dummy->next = root;
        ListNode *left_before = dummy;

        // Move `left_before` to the node just before the `left` node
        for (int i = 1; i < left; i++)
        {
            left_before = left_before->next;
        }

        ListNode *left_node = left_before->next;
        ListNode *prev = nullptr;
        ListNode *curr = left_node;

        // Reverse the sublist between left and right
        for (int i = 0; i < right - left + 1; i++)
        {
            ListNode *next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        // Connect the reversed portion with the remaining list
        left_before->next = prev;
        left_node->next = curr;

        return dummy->next;
    }
};
