#include <bits/stdc++.h>
using namespace std;

vector<bool> solution(vector<vector<int>> &operations)
{
    int max_width = 0;
    int max_height = 0;
    vector<bool> result;

    for (const auto &op : operations)
    {
        if (op[0] == 0)
        {
            int width = op[1];
            int height = op[2];
            max_width = max(max_width, max(width, height));
            max_height = max(max_height, min(width, height));
        }
        else if (op[0] == 1)
        {
            int box_width = op[1];
            int box_height = op[2];
            bool can_fit1 = (max_width <= max(box_width, box_height) &&
                             max_height <= min(box_width, box_height));
            bool can_fit2 = (max_height <= max(box_width, box_height) &&
                             max_width <= min(box_width, box_height));
            result.push_back(can_fit1 || can_fit2);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> operations = {{0, 1, 3}, {0, 4, 2}, {1, 3, 4}, {1, 3, 2}};
    vector<bool> res = solution(operations);

    for (bool b : res)
    {
        cout << (b ? "true" : "false") << endl;
    }

    return 0;
}
