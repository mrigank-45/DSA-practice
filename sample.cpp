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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_map<int, bool> mp;
        for (auto it : nums)
            mp[it] = true;
        int count = 0;
        bool flag = false;
        while (head != NULL)
        {
            if (mp.find(head->val) == mp.end())
            {
                if (flag == true)
                {
                    count++;
                    flag = false;
                }
            }
            else
            {
                flag = true;
            }
            head = head->next;
        }
        if(flag == true) count++;
        return count;
    }
};
