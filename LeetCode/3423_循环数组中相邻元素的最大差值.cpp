// 3423_循环数组中相邻元素的最大差值.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDistance = 0;
        size_t n = nums.size();
        for (size_t i = 0; i < n; i++) {
            maxDistance = max(maxDistance, abs(nums[i] - nums[(i + 1) % n]));
        }
        return maxDistance;
    }
};
