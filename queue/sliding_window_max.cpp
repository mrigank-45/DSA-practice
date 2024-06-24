// Sliding Window Maximum | Leetcode

#include <iostream>
#include <queue>
using namespace std;

vector<int> solve(vector<int> arr, int k)
{

    deque<int> maxi(k);
    int n = arr.size();
    vector<int> ans;

    // Addition of first k size window

    for (int i = 0; i < k; i++)
    {

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);
    }

    ans.push_back(arr[maxi.front()]);

    // remaining windows ko process karlo
    for (int i = k; i < n; i++)
    {

        // next window

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        // addition

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        maxi.push_back(i);

        ans.push_back(arr[maxi.front()]);
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 3;
    vector<int> ans = solve(arr, k);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
