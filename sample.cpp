#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.size();

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '*')
            {
                st.push(s[i]);
            }
            else
            {
                int cnt = 0;
                while (!st.empty() && st.top() != '(')
                {
                    cnt++;
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                    while (cnt--)
                    {
                        st.push('*');
                    }
                }
                else
                {
                    if(cnt==0)
                    {
                        return false;
                    }
                    cnt--;
                    while (cnt--)
                    {
                        st.push('*');
                    }
                }
            }
        }

        int cnt = 0;

        while (!st.empty())
        {
            if (st.top() == '*')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (cnt < 0)
            {
                return false;
            }
            st.pop();
        }
        return true;
    }
};
