// ALGO:
// 1. Since all the arrays are sorted, the first element of all K arrays can be stored in the Min heap because the first element of 
// the sorted array must be one of those elements. 
// 2. Remove the first element from the Min heap and add it to the answer array. Add the next element of the same row from which the 
// element was removed, in the Min heap. Now one of these K elements must be the second element in the sorted array.
// 3. Repeat the same process until all the elements are added to the answer array in a sorted manner.

// Same logic can be used for merging k sorted linked lists (just take head* and tail* for ans linked list)

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> &arr)
{
    int n = arr.size() * arr[0].size();

    // { data, { row , column } }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    // step 1
    for (int i = 0; i < arr.size(); i++)
    {
        minHeap.push({arr[i][0], {i, 0}});
    }

    vector<int> sortedArray;

    // step 2 ans 3
    while (!minHeap.empty())
    {
        sortedArray.push_back(minHeap.top().first);
        pair<int, int> index = {minHeap.top().second.first, minHeap.top().second.second + 1};
        minHeap.pop();

        if (index.second != arr[0].size()) // if next element exists
        {
            minHeap.push({arr[index.first][index.second], {index.first, index.second}});
        }
    }

    return sortedArray;
}
