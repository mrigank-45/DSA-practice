#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumOperations(string num)
    {
        // 52,57,05,00
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        cout<<"size: "<<num.size()<<endl;

        for (int i = num.size() - 1; i >= 0; i--)
        {
            bool flag = false;

            if ((num[i] == '5') && c1 == 0)
            {
                c1++;
                cout<<"i: "<<i<<endl;
                cout << "c1: " << c1 << " c2: " << c2 << " c3: " << c3 << " c4: " << c4 << endl;
            }
            if ((num[i] == '5') && c2 == 0)
            {
                c2++;
                cout<<"i: "<<i<<endl;
                cout << "c1: " << c1 << " c2: " << c2 << " c3: " << c3 << " c4: " << c4 << endl;
            }
            if ((num[i] == '0') && c3 == 0)
            {
                c3++;
                cout<<"i: "<<i<<endl;
                cout << "c1: " << c1 << " c2: " << c2 << " c3: " << c3 << " c4: " << c4 << endl;
            }
            if ((num[i] == '0') && c4 == 0)
            {
                c4++;
                cout<<"i: "<<i<<endl;
                cout << "c1: " << c1 << " c2: " << c2 << " c3: " << c3 << " c4: " << c4 << endl;
                flag = true;
            }

            if ((num[i] == '2') && c1 == 1)
            {
                return num.size() - i - 2;
            }
            if ((num[i] == '7') && c2 == 1)
            {
                return num.size() - i - 2;
            }
            if ((num[i] == '5') && c3 == 1)
            {
                return num.size() - i - 2;
            }
            if ((num[i] == '0') && c4 == 1 && flag == false)
            {
                return num.size() - i - 2;
            }
        }

        if (c3 == 1 || c4 == 1)
        {
            return num.size() - 1;
        }
        else
        {
            return num.size();
        }
    }
};
