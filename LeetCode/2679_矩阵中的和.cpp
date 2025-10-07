// 2679_¾ØÕóÖĞµÄºÍ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        size_t m = nums.size(), n = nums.front().size();
        for (size_t i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end());
        }
        int result = 0;
        for (size_t j = 0; j < n; j++) {
            int maximum = INT_MIN;
            for (size_t i = 0; i < m; i++) {
                maximum = max(maximum, nums[i][j]);
            }
            result += maximum;
        }
        return result;
    }
};
