// 1582_二进制矩阵中的特殊位置.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        size_t m = mat.size(), n = mat.front().size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int result = 0;
        for (size_t i = 0; i < m; i++) {
            if (rows[i] == 1) {
                for (size_t j = 0; j < n; j++) {
                    if (cols[j] == 1 && mat[i][j] == 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
