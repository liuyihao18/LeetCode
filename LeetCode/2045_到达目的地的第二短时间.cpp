// 2045_����Ŀ�ĵصĵڶ���ʱ��.cpp
#include "custom.h"
ustd

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // path[i][0] ��ʾ�� 1 �� i �����·���ȣ�path[i][1] ��ʾ�� 1 �� i ���ϸ�ζ�·����
        vector<vector<int>> path(n + 1, vector<int>(2, INT_MAX));
        path[1][0] = 0;
        queue<pair<int, int>> q;
        q.push({ 1,0 });
        while (path[n][1] == INT_MAX) {
            const auto& node = q.front();
            int curr = node.first, len = node.second;
            q.pop();
            for (auto next : graph[curr]) {
                if (len + 1 < path[next][0]) {
                    path[next][0] = len + 1;
                    q.push({ next, len + 1 });
                }
                else if (len + 1 > path[next][0] && len + 1 < path[next][1]) {
                    path[next][1] = len + 1;
                    q.push({ next, len + 1 });
                }
            }
        }
        
        int ret = 0;
        for (int i = 0; i < path[n][1]; i++) {
            if (ret % (2 * change) >= change) { // ���
                ret = ret + (2 * change - ret % (2 * change)); // t_wait
            }
            ret = ret + time;
        }
        return ret;
    }
};
