// 807_保持城市天际线.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxIncreaseKeepingSkyline(const vector<vector<int>>& grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }
        vector<int> row_heights;
        vector<int> col_heights;
        for (size_t i = 0; i < grid.size(); i++) {
            int _max = 0;
            for (size_t j = 0; j < grid.front().size(); j++) {
                _max = max(_max, grid[i][j]);
            }
            row_heights.push_back(_max);
        }
        for (size_t j = 0; j < grid.front().size(); j++) {
            int _max = 0;
            for (size_t i = 0; i < grid.size(); i++) {
                _max = max(_max, grid[i][j]);
            }
            col_heights.push_back(_max);
        }
        int result = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid.front().size(); j++) {
                result += min(row_heights[i], col_heights[j]) - grid[i][j];
            }
        }
        return result;
    }
};
