// 剑指_Offer_II_115_重建序列.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = static_cast<int>(nums.size());
        vector<int> inDegree(n + 1);
        vector<unordered_set<int>> graph(n + 1);
        for (const auto& sequence : sequences) {
            for (size_t i = 0; i + 1 < sequence.size(); i++) {
                int u = sequence[i];
                int v = sequence[i + 1];
                if (!graph[u].count(v)) {
                    graph[u].insert(v);
                    inDegree[v]++;
                }
            }
        }
        queue<int> q;
        for (int i = 1; i < n + 1; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            if (q.size() > 1) {
                return false;
            }
            int u = q.front();
            q.pop();
            for (auto v : graph[u]) {
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return true;
    }
};
