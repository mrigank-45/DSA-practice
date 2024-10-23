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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        int n = 0;
        ListNode *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        int length = n / k, rem = n % k;
        ListNode *curr = head;
        for (int i = 0; i < k; i++)
        {
            ListNode *temp = new ListNode(0);
            ListNode *write = temp;
            for (int j = 0; j < length + (i < rem ? 1 : 0); j++)
            {
                if (!curr)
                    continue;
                write->next = new ListNode(curr->val);
                write = write->next;
                if (curr)
                    curr = curr->next;
            }
            ans.push_back(temp->next);
        }
        return ans;
    }
};
