// Maximum Value of an Ordered Triplet II

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> arr)
    {
        int n = arr.size();
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> largestElementOnRight(vector<int> arr)
    {
        int n = arr.size();

        vector<int> ans(n);
        ans[n - 1] = -1;

        int maxi = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            ans[i] = maxi;

            if (arr[i] > arr[maxi])
            {
                maxi = i;
            }
        }
        return ans;
    }

    long long maximumTripletValue(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> nextSmaller = nextSmallerElement(nums);
        vector<int> largestOnRight = largestElementOnRight(nums);

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            int temp = nextSmaller[i];

            while (temp != -1 && largestOnRight[temp] != -1)
            {
                ans = max(ans, (long long)((nums[i] - nums[temp]) * nums[largestOnRight[temp]]));
                temp = nextSmaller[temp];
            }
        }

        return ans;
    }
};
