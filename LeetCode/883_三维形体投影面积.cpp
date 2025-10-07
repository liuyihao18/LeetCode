// 883_三维形体投影面积.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        vector<int> xz(51, 0);
        vector<int> yz(51, 0);
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid.front().size());
        int area = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    area++;
                    xz[i] = max(xz[i], grid[i][j]);
                    yz[j] = max(yz[j], grid[i][j]);
                }
            }
        }
        for (int i = 0; i < 51; i++) {
            area += xz[i];
            area += yz[i];
        }
        return area;
    }
};
