// 1470_重新排列数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result(nums.size());
        for (size_t i = 0; i < n; i++) {
            result[2 * i] = nums[i];
            result[2 * i + 1] = nums[i + n];
        }
        return result;
    }
};
