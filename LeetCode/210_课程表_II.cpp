// 210_¿Î³Ì±í_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (const auto& prerequisite : prerequisites) {
            int u = prerequisite.back(), v = prerequisite.front();
            inDegree[v]++;
            edges[u].push_back(v);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.emplace(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            for (auto v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        return result.size() == numCourses ? result : vector<int>();
    }
};
