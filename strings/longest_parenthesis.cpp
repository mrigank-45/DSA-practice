// Longest Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();

        stack<int>st;
        st.push(-1);  // represents base index till when parathesis is not valid
        int maxx=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    maxx=max(maxx,i-st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return maxx;
    }
};
