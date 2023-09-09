// 207_¿Î³Ì±í.cpp
#include "custom.h"
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
        priority_queue<int> pq;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                pq.emplace(i);
            }
        }
        int cnt = 0;
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            cnt++;
            for (auto v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    pq.emplace(v);
                }
            }
        }
        return cnt == numCourses;
    }
};
