// 1464_数组中两元素的最大乘积.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto maxIter = max_element(nums.begin(), nums.end());
        auto max1 = *maxIter;
        nums.erase(maxIter);
        maxIter = max_element(nums.begin(), nums.end());
        auto max2 = *maxIter;
        return (max1 - 1) * (max2 - 1);
        /*
        nth_element(nums.begin(), nums.begin() + 1, nums.end(), greater<>());
        return (nums[0] - 1) * (nums[1] - 1);
        */
    }
};
