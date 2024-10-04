#include <iostream>
#include <string>
using namespace std;

string expandString(string &inputStr) {
    string result;
    int i = 0;
    while (i < inputStr.size()) {
        if (inputStr[i] == '(') {
            // Find the closing parenthesis
            int j = i + 1;
            while (j < inputStr.size() && inputStr[j] != ')') {
                j++;
            }
            // Extract the pattern
            string pattern = inputStr.substr(i + 1, j - i - 1);
            i = j + 1; // Move to the '{'

            // Find the closing curly bracket
            j = i + 1;
            while (j < inputStr.size() && inputStr[j] != '}') {
                j++;
            }
            // Extract the count
            int count = stoi(inputStr.substr(i + 1, j - i - 1));
            i = j + 1; // Move past the '}'

            // Expand the pattern
            for (int k = 0; k < count; k++) {
                result += pattern;
            }
        } else {
            result += inputStr[i];
            i++;
        }
    }
    return result;
}

int main() {
    // Test case 1
    string input1 = "(ab){3}";
    cout << "Input: " << input1 << endl;
    cout << "Output: " << expandString(input1) << endl; // Expected output: ababab

    // Test case 2
    string input2 = "(ab){3}(cd){2}";
    cout << "Input: " << input2 << endl;
    cout << "Output: " << expandString(input2) << endl; // Expected output: abababcdcd

    // Additional test cases
    string input3 = "(a){5}(b){3}";
    cout << "Input: " << input3 << endl;
    cout << "Output: " << expandString(input3) << endl; // Expected output: aaaaabbb

    string input4 = "(xyz){2}(pq){4}";
    cout << "Input: " << input4 << endl;
    cout << "Output: " << expandString(input4) << endl; // Expected output: xyzxyzpqpqpqpq

    return 0;
}
