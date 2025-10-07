// 1380_矩阵中的幸运数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        size_t n = matrix.front().size();
        vector<int> row_min(m, INT_MAX);
        vector<int> col_max(n, INT_MIN);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                row_min[i] = min(row_min[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }
        vector<int> result;
        sort(col_max.begin(), col_max.end());
        for (auto num : row_min) {
            if (*lower_bound(col_max.begin(), col_max.end(), num) == num) {
                result.push_back(num);
            }
        }
        return result;
    }
};
