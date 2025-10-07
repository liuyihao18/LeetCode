// 1765_地图中的最高点.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Node {
        size_t i;
        size_t j;
        int h;
    };
public:
    vector<vector<int>> highestPeak(const vector<vector<int>>& isWater) {
        queue<Node> q;
        vector<vector<int>> map(isWater.size(), vector<int>(isWater.front().size(), -1));
        size_t m = isWater.size(), n = isWater.front().size();
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (isWater[i][j]) {
                    q.push({ i,j,0 });
                }
            }
        }
        while (!q.empty()) {
            Node curr = q.front();
            q.pop();
            if (curr.i == -1 || curr.j == -1 || curr.i >= m || curr.j >= n) {
                continue;
            }
            if (map[curr.i][curr.j] >= 0) {
                continue;
            }
            map[curr.i][curr.j] = curr.h;
            q.push({ curr.i, curr.j + 1, curr.h + 1 });
            q.push({ curr.i + 1, curr.j, curr.h + 1 });
            q.push({ curr.i, curr.j - 1, curr.h + 1 });
            q.push({ curr.i - 1, curr.j, curr.h + 1 });
        }
        return map;
    }
};
