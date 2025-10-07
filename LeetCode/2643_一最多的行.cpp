// 2643_一最多的行.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        size_t m = mat.size(), n = mat[0].size();
        int rowIndex = 0, maxCount = 0;
        for (int i = 0; i < m; i++) {
            int count = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (count > maxCount) {
                maxCount = count;
                rowIndex = i;
            }
        }
        return { rowIndex, maxCount };
    }
};
