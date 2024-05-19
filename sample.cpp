#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        deque<int> digits;

        int temp = 0;
        int point = 0;

        while (n)
        {
            if (n % 10 < temp)
            {
                auto it = upper_bound(digits.begin(), digits.end(), n % 10);
                int result = *it;
                digits.erase(it);
                digits.push_back(n % 10);

                point = result;
                n /= 10;

                break;
            }

            temp = n % 10;
            digits.push_back(n % 10);
            n /= 10;
        }

        if (point == 0)
        {
            return -1;
        }

        sort(digits.begin(), digits.end());

        digits.push_front(point);

        while (n)
        {
            digits.push_front(n % 10);
            n /= 10;
        }

        int ans = 0;

        for (auto val : digits)
        {
            // int overflow check
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && val > 7))
            {
                return -1;
            }
            else
            {
                ans = ans * 10 + val;
            }
        }

        return ans;
    }
};
