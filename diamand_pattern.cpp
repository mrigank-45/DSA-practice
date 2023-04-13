#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i < (n / 2))
        {

            int k = (1 + (i - 1) * 2);
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= k; j++)
            {

                cout << "*";
            }
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
        else if (i == n / 2)
        {
            int k = (1 + (i - 1) * 2);
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= k; j++)
            {

                cout << "*";
            }
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            cout << endl;
            
            if (n % 2 == 0)
            {
                for (int j = 1; j <= (n - k) / 2; j++)
                {
                    cout << " ";
                }
                for (int j = 1; j <= k; j++)
                {

                    cout << "*";
                }
                for (int j = 1; j <= (n - k) / 2; j++)
                {
                    cout << " ";
                }
                cout << endl;
            }
            else
            {
                for (int j = 1; j <= ((n - k) / 2)-1; j++)
                {
                    cout << " ";
                }
                for (int j = 1; j <= k + 2; j++)
                {

                    cout << "*";
                }
                for (int j = 1; j <= ((n - k) / 2)-1; j++)
                {
                    cout << " ";
                }
                cout << endl;
            }
        }
        else
        {
            int k = (1 + ((n - i) - 1) * 2);
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= k; j++)
            {

                cout << "*";
            }
            for (int j = 1; j <= (n - k) / 2; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
