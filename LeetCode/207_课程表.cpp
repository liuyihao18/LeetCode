// 207_¿Î³Ì±í.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (const auto& prerequisite : prerequisites) {
            int u = prerequisite.front(), v = prerequisite.back();
            inDegree[v]++;
            edges[u].push_back(v);
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.emplace(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (auto v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        return cnt == numCourses;
    }
};
