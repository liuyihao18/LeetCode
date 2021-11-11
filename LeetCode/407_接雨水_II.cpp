// 407_½ÓÓêË®_II.cpp
#include "custom.h"
ustd

class Solution {
    struct Node
    {
        int x{ 0 };
        int y{ 0 };
        int h{ 0 };
    };
    struct NodeCmp {
        bool operator()(const Node& n1, const Node& n2) const {
            return n1.h > n2.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        size_t m = heightMap.size();
        size_t n = heightMap[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n));
        priority_queue<Node,vector<Node>, NodeCmp> q;
        for (int i = 0; i < m; i++) {
            q.push({ i, 0, heightMap[i][0] });
            q.push({ i, static_cast<int>(n - 1), heightMap[i][n - 1] });
            visit[i][0] = visit[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            q.push({ 0, j, heightMap[0][j] });
            q.push({ static_cast<int>(m - 1),j, heightMap[m - 1][j] });
            visit[0][j] = visit[m - 1][j] = true;
        }
        int dirs[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
        int ans = 0;
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            for (auto dir : dirs) {
                int nx = node.x + dir[0];
                int ny = node.y + dir[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (visit[nx][ny]) {
                    continue;
                }
                if (node.h > heightMap[nx][ny]) {
                    ans += node.h - heightMap[nx][ny];
                }
                q.push({ nx,ny,max(node.h, heightMap[nx][ny]) });
                visit[nx][ny] = true;
            }
        }
        return ans;
    }
};
