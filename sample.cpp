#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        if (num == 0)
            return 1;
        int count = 0;
        while (num > 0)
        {
            num /= 10;
            count++;
        }
        return count;
    }

    vector<long long> RangeSumDigits(int n, vector<int> &arr, int Q, vector<vector<int>> &Queries)
    {
        vector<long long> result;
        vector<int> digits(n);

        // Initialize the digits array
        for (int i = 0; i < n; ++i)
        {
            digits[i] = countDigits(arr[i]);
        }

        // Process each query
        for (const auto &query : Queries)
        {
            int type = query[0];
            int l = query[1] - 1;
            int r = query[2] - 1;

            if (type == 1)
            {
                // Update the array elements to their digit counts in the given range
                for (int j = l; j <= r; ++j)
                {
                    arr[j] = digits[j];
                }
            }
            else if (type == 2)
            {
                // Calculate the sum for the given range and store it in the result
                long long rangeSum = 0;
                for (int j = l; j <= r; ++j)
                {
                    rangeSum += arr[j];
                }
                result.push_back(rangeSum);
            }

            // Update digits array after processing each query
            for (int i = l; i <=r; ++i)
            {
                digits[i] = countDigits(arr[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    vector<int> arr = {11, 1234, 5, 622};
    int Q = 4;
    vector<vector<int>> Queries = {{1, 2, 3}, {2, 2, 2}, {1, 1, 2}, {2, 1, 4}};

    vector<long long> result = solution.RangeSumDigits(n, arr, Q, Queries);

    for (long long res : result)
    {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
