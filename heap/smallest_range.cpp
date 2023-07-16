#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // or we could use struct or simply use pair<int,pair<int,int>> in min heap.
    class node
    {
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c)
        {
            data = d;
            row = r;
            col = c;
        }
    };

    class compare
    {
    public:
        bool operator()(node *a, node *b)
        {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>> &nums)
    {

        int k = nums.size();

        priority_queue<node *, vector<node *>, compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Step 1: Create min heap for starting element of k lists
        for (int i = 0; i < k; i++)
        {
            int element = nums[i][0];
            maxi = max(maxi, element);
            mini = min(mini, element);
            pq.push(new node(nums[i][0], i, 0));
        }

        int st = mini;
        int en = maxi;

        // Step 2: Process ranges
        while (!pq.empty())
        {
            node *temp = pq.top();
            pq.pop();

            mini = temp->data; // update mini

            // update range
            if (maxi - mini < en - st)
            {
                st = mini;
                en = maxi;
            }

            if (temp->col + 1 < nums[temp->row].size()) // if the next element exists in that array
            {
                maxi = max(maxi, nums[temp->row][temp->col + 1]); // update maxi
                pq.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else
            {
                break;
            }
        }

        return {st, en};
    }
};
