#include <iostream>
#include <string>

using namespace std;

string findOriginalString(const string &modifiedStr)
{
    string str = "";
    for (char ch : modifiedStr)
    {
        if (ch != 'i')
        {
            str += ch;
        }
    }

    if (str.length() % 2 == 1)
    {
        return "notpossible";
    }
    else
    {
        // get the first half of string
        string firstHalf = str.substr(0, str.length() / 2);

        // get second half
        string secondHalf = str.substr(str.length() / 2);

        int len = firstHalf.length();

        int n = modifiedStr.length() - len;

        // get first n of modifiedStr
        string ans = modifiedStr.substr(0, n);

        return ans;

        
    }
}

int main()
{
    string modifiedStr = "izizibibzzbb";

    string originalStr = findOriginalString(modifiedStr);
    cout << originalStr << endl;

    return 0;
}
