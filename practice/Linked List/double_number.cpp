// Double a Number Represented as a Linked List 

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
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
    ListNode *reverse(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return rest;
    }

    void insertAtTail(ListNode *&head, int d)
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        ListNode *newNode = new ListNode(d, nullptr);
        temp->next = newNode;
        temp = newNode;
    }

    ListNode *doubleIt(ListNode *head)
    {
        if (head == NULL || head->val == 0)
        {
            ListNode *newHead = new ListNode(0);

            return newHead;
        }

        ListNode *head2 = reverse(head);

        int val = (head2->val * 2) % 10;
        ListNode *newHead = new ListNode(val);
        int carry = (head2->val * 2) / 10;

        ListNode *temp = head2->next;

        while (temp != NULL)
        {
            int val = ((temp->val * 2) + carry) % 10;
            carry = ((temp->val * 2) + carry) / 10;

            insertAtTail(newHead, val);

            temp = temp->next;
        }

        if (carry != 0)
        {
            insertAtTail(newHead, carry);
        }

        ListNode *newHead2 = reverse(newHead);

        return newHead2;
    }
};
