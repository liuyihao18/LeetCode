// 1072_按列翻转得到最大值等行数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> um;
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        for (size_t i = 0; i < m; i++) {
            string temp;
            for (size_t j = 0; j < n; j++) {
                temp += '0' + (matrix[i][j] ^ matrix[i][0]);
            }
            um[temp]++;
        }
        return max_element(um.begin(), um.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
            return p1.second < p2.second;
            })->second;
    }
};
