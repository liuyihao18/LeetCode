// 3128_Ö±½ÇÈý½ÇÐÎ.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {        
        vector<vector<size_t>> row1Index(grid.size());
        vector<int> col1Count(grid[0].size(), 0);
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    row1Index[i].push_back(j);
                    col1Count[j] += 1;
                }
            }
        }
        long long result = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            for (size_t j : row1Index[i]) {
                if (row1Index[i].size() >= 2 && col1Count[j] >= 2) {
                    result += (row1Index[i].size() - 1) * (col1Count[j] - 1);
                }
            }
        }
        return result;
    }
};
