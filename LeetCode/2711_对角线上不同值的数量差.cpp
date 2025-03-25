// 2711_对角线上不同值的数量差.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        size_t m = grid.size(), n = grid[0].size();
        vector<vector<int>> topLeft(m, vector<int>(n, 0));
        vector<vector<int>> bottomRight(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            unordered_set<int> s;
            for (size_t k = 0; i + k < m && k < n; k++) {
                topLeft[i + k][k] = static_cast<int>(s.size());
                s.insert(grid[i + k][k]);
            }
        }
        for (size_t j = 1; j < n; j++) {
            unordered_set<int> s;
            for (size_t k = 0; k < m && j + k < n; k++) {
                topLeft[k][j + k] = static_cast<int>(s.size());
                s.insert(grid[k][j + k]);
            }
        }
        for (size_t i = 0; i < m; i++) {
            unordered_set<int> s;
            for (size_t k = 0; m - k - i > 0 && n - k > 0; k++) {
                bottomRight[m - k - i - 1][n - k - 1] = static_cast<int>(s.size());
                s.insert(grid[m - k - i - 1][n - k - 1]);
            }
        }
        for (size_t j = 1; j < n; j++) {
            unordered_set<int> s;
            for (size_t k = 0; m - k > 0 && n - k - j > 0; k++) {
                bottomRight[m - k - 1][n - k - j - 1] = static_cast<int>(s.size());
                s.insert(grid[m - k - 1][n - k - j - 1]);
            }
        }
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                answer[i][j] = abs(topLeft[i][j] - bottomRight[i][j]);
            }
        }
        return answer;
    }
};
