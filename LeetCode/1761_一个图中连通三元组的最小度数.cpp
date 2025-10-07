// 1761_一个图中连通三元组的最小度数
#include "stdafx.h"
ustd

class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<int> degree(n, 0);
        for (const auto& edge : edges) {
            int u = edge.front(), v = edge.back();
            graph[u - 1][v - 1] = 1;
            graph[v - 1][u - 1] = 1;
            degree[u - 1]++;
            degree[v - 1]++;
        }
        int minDegree = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (graph[i][j] == 1) {
                    for (int k = j + 1; k < n; k++) {
                        if (graph[i][k] == 1 && graph[j][k] == 1) {
                            minDegree = min(
                                minDegree,
                                degree[i] + degree[j] + degree[k] - 6
                            );
                        }
                    }
                }
            }
        }
        return minDegree == INT_MAX ? -1 : minDegree;
    }
};
