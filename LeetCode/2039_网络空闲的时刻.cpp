// 2039_ÍøÂç¿ÕÏÐµÄÊ±¿Ì.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // ±ßÁ´±í
        size_t n = patience.size();
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            // Ë«Ïò±ß
            graph[edge.front()].push_back(edge.back());
            graph[edge.back()].push_back(edge.front());
        }
        // ¾àÀë
        vector<int> distances(n, -1);
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            if (distances[curr.first] != -1) {
                continue;
            }
            distances[curr.first] = curr.second;
            for (auto e : graph[curr.first]) {
                q.push({ e, curr.second + 1 });
            }
        }
        int result = 0;
        for (size_t i = 1; i < n; i++) {
            int time = patience[i] * ((2 * distances[i] - 1) / patience[i]) + 2 * distances[i] + 1;
            result = max(result, time);
        }
        return result;
    }
};
