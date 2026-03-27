// 2946_循环移位后的矩阵相似检查.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool areSimilar(const vector<vector<int>>& mat, size_t k) {
        const size_t m = mat.size(), n = mat.front().size();
        k %= n;
        for (size_t i = 0; i < m; i++)
        {
	        for (size_t j = 0; j < n; j++)
	        {
		        if (mat[i][j] != mat[i][(j + k) % n])
		        {
					return false;
		        }
	        }
        }
		return true;
    }
};
