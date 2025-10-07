// 2596_检查骑士巡视方案.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) {
            return false;
        }
        int n = static_cast<int>(grid.size());
        vector<pair<int, int>> route(n * n, {0, 0});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                route[grid[i][j]] = { i,j };
            }
        }
        for (int i = 0; i + 1 < route.size(); i++) {
            pair<int, int> pos = route[i];
            pair<int, int> nextPos = route[i + 1];
            int xDiff = abs(pos.first - nextPos.first);
            int yDiff = abs(pos.second - nextPos.second);
            if (!(xDiff == 1 && yDiff == 2 || xDiff == 2 && yDiff == 1)) {
                return false;
            }
        }
        return true;
    }
};
