// 1260_¶þÎ¬Íø¸ñÇ¨ÒÆ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                temp.push_back(grid[i][j]);
            }
        }
        k = -(k % static_cast<int>(temp.size()));
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[0].size(); j++) {
                if (k < 0) {
                    grid[i][j] = temp[temp.size() + k];
                }
                else {
                    grid[i][j] = temp[k];
                }
                k++;
            }
        }
        return grid;
    }
};
