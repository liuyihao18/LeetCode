// 1129_颜色交替的最短路径.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n);
        vector<vector<int>> blue(n);
        for (const auto& redEdge : redEdges) {
            red[redEdge[0]].push_back(redEdge[1]);
        }
        for (const auto& blueEdge : blueEdges) {
            blue[blueEdge[0]].push_back(blueEdge[1]);
        }
        set<pair<int, int>> visited;
        queue<pair<pair<int, int>, int>> q;
        vector<int> answer(n, INT_MAX);
        answer[0] = 0;
        q.push({ { 0, 1 }, 0 });
        q.push({ { 0, -1 }, 0 });
        while (!q.empty()) {
            pair<pair<int, int>, int> curr = q.front();
            q.pop();
            if (visited.count(curr.first)) {
                continue;
            }
            visited.insert(curr.first);
            int u = curr.first.first;
            decltype(&red) ptr = nullptr;
            if (curr.first.second == 1) {
                ptr = &red;
            }
            else {
                ptr = &blue;
            }
            int path = curr.second + 1;
            for (auto v : (*ptr)[u]) {
                answer[v] = min(answer[v], path);
                q.push({ { v, -curr.first.second }, path });
            }
        }
        for (auto& i : answer) if (i == INT_MAX) i = -1;
        return answer;
    }
};

