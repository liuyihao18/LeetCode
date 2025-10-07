// 2012_数组美丽值求和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMin(n, 0);
        leftMax[0] = INT_MIN;
        for (size_t i = 1; i < n - 1; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        rightMin[n - 1] = INT_MAX;
        for (size_t i = n - 2; i > 0; i--) {
            rightMin[i] = min(rightMin[i + 1], nums[i + 1]);
        }
        int beauties = 0;
        for (size_t i = 1; i < n - 1; i++) {
            if (leftMax[i] < nums[i] && nums[i] < rightMin[i]) {
                beauties += 2;
            }
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                beauties += 1;
            }
        }
        return beauties;
    }
};
