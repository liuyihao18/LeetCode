// 886_可能的二分法.cpp
#include "custom.h"
ustd

class Solution {
    bool dfs(int u, const vector<vector<int>>& graph, vector<int>& color) {
        int curr = color[u];
        for (auto v : graph[u]) {
            if (color[v] == curr) {
                return false;
            }
            if (color[v] == 0) {
                color[v] = -curr;
                if (!dfs(v, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        for (const auto& dislike : dislikes) {
            graph[(size_t)dislike[0] - 1].push_back(dislike[1] - 1);
            graph[(size_t)dislike[1] - 1].push_back(dislike[0] - 1);
        }
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!dfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
