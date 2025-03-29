// 2360_图中的最长环.cpp
#include "custom.h"
ustd

class Solution {
    void dfs(int node, const vector<int>& edges, vector<bool>& visited, int& maxLength) {
        size_t n = edges.size();
        unordered_map<int, int> length;
        int currNode = node;
        int currLength = 0;
        while (true) {
            if (visited[currNode]) {
                if (length.count(currNode)) {
                    maxLength = max(maxLength, currLength - length[currNode]);
                }
                break;
            }
            visited[currNode] = true;
            length[currNode] = currLength++;
            if (edges[currNode] < 0) {
                break;
            }
            currNode = edges[currNode];
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        size_t n = edges.size();
        vector<bool> visited(n, false);
        int maxLength = -1;
        for (size_t i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, edges, visited, maxLength);
            }
        }
        return maxLength;
    }
};
