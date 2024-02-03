// Count Visited Nodes in a Directed Graph
// https://www.youtube.com/watch?v=PeRT2KfLQYQ&embeds_referring_euri=https%3A%2F%2Fleetcode.com%2F&source_ve_path=OTY3MTQ&feature=emb_imp_woyt

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int sz = edges.size();

        vector<int> answer(sz); // ans array
        set<int> visited;       // to keep check of the visited node

        for (int index = 0; index < sz; ++index) // each index is considered
        {
            visited.clear();
            vector<int> nodeStack; // path for curr starting point

            int currSrc = index;
            // continue till node is visited or already computed
            while (visited.find(currSrc) == visited.end() && answer[currSrc] == 0)
            {
                visited.insert(currSrc);
                nodeStack.push_back(currSrc);
                currSrc = edges[currSrc]; // next node to visited
            }

            // if a cycle is formed
            if (visited.find(currSrc) != visited.end())
            {
                int cycleLength = nodeStack.size() - distance(nodeStack.begin(), find(nodeStack.begin(), nodeStack.end(), currSrc));

                // update ans for all nodes in the cycle as cycleLength
                for (int times = 0; times < cycleLength; times++)
                {
                    answer[nodeStack.back()] = cycleLength;
                    nodeStack.pop_back();
                }
            }

            // update ans for nodes which are not part of cycle but directly connected to the cycle
            while (!nodeStack.empty())
            {
                currSrc = nodeStack.back();
                nodeStack.pop_back();
                answer[currSrc] = answer[edges[currSrc]] + 1;
            }
        }

        return answer;
    }
};
