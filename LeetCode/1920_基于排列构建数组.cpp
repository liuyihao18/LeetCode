// 1920_基于排列构建数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> result(n, 0);
        for (size_t i = 0; i < n; i++) {
            result[i] = nums[nums[i]];
        }
        return result;
    }
};
