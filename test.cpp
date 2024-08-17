#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(const vector<vector<string>>& paragraphs, int width) {
    vector<string> result;
    const string border(width + 2, '*'); // Top and bottom border
    result.push_back(border);

    for (const auto& paragraph : paragraphs) {
        string line = "*"; // Start the line with a left border asterisk

        for (size_t i = 0; i < paragraph.size(); ++i) {
            const auto& chunk = paragraph[i];
            if (line.size() + chunk.size() + 1 > width + 1) { // Check if adding the next chunk exceeds the width
                // Center the current line if it has content
                if (line.size() > 1) {
                    int total_spaces = width - (line.size() - 1); // Total spaces needed
                    int left_spaces = total_spaces / 2;
                    int right_spaces = total_spaces - left_spaces;
                    line = "*" + string(left_spaces, ' ') + line.substr(1) + string(right_spaces, ' ') + "*";
                    result.push_back(line);
                }
                line = "*"; // Start a new line
                line += chunk; // Add the current chunk to the new line
            } else {
                if (line.size() > 1) { // If line already has some content, add a space before the next chunk
                    line += " ";
                }
                line += chunk;
            }
        }

        // Push the last line of the paragraph only if it has content
        if (line.size() > 1) {
            int total_spaces = width - (line.size() - 1); // Total spaces needed
            int left_spaces = total_spaces / 2;
            int right_spaces = total_spaces - left_spaces;
            line = "*" + string(left_spaces, ' ') + line.substr(1) + string(right_spaces, ' ') + "*";
            result.push_back(line);
        }
    }

    result.push_back(border); // Bottom border

    return result;
}

int main() {
    // vector<vector<string>> paragraphs = {
    //     {"there", "are"},
    //     {"four seasons", "in a year"},
    //     {"summer", "autumn", "winter", "spring"}
    // };
    // int width = 12;

     vector<vector<string>> paragraphs = {
        {"hello", "world"},
        {"How", "areYou", "doing"},
        {"Please look", "and align", "to center"}
    };
    int width = 16;

    vector<string> formattedPage = solution(paragraphs, width);
    for (const auto& line : formattedPage) {
        cout << line << endl;
    }

    return 0;
}
