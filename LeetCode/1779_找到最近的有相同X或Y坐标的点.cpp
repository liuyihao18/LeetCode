// 1779_找到最近的有相同X或Y坐标的点.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_idx = -1;
        int min_dis = INT_MAX;
        for (int i = 0; i < static_cast<int>(points.size()); i++) {
            const auto& point = points[i];
            if (x == point[0] || y == point[1]) {
                int dis = abs(x - point[0]) + abs(y - point[1]);
                if (dis < min_dis) {
                    min_dis = dis;
                    min_idx = i;
                }
            }
        }
        return min_idx;
    }
};
