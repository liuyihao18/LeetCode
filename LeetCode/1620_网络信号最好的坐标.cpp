// 1620_网络信号最好的坐标.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int min_x = INT_MAX, min_y = INT_MAX;
        int max_x = INT_MIN, max_y = INT_MIN;

        for (const auto& tower : towers) {
            min_x = min(min_x, tower[0]);
            min_y = min(min_y, tower[1]);
            max_x = max(max_x, tower[0]);
            max_y = max(max_y, tower[1]);
        }

        int max_s = INT_MIN;
        vector<int> pos(2, 0);
        for (int x = min_x; x <= max_x; x++) {
            for (int y = min_y; y <= max_y; y++) {
                int s = 0;
                for (const auto& tower : towers) {
                    double d = sqrt((x - tower[0]) * (x - tower[0]) + (y - tower[1]) * (y - tower[1]));
                    if (d <= radius) {
                        s += static_cast<int>(tower[2] * 1.0 / (1 + d));
                    }
                }
                if (s > max_s) {
                    max_s = s;
                    pos[0] = x;
                    pos[1] = y;
                }
            }
        }
        
        if (max_s == 0) {
            return { 0, 0 };
        }

        return pos;
    }
};
