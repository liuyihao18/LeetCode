// 1005_K次取反后最大化的数组和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int sum = 0;
        int boarder = abs(nums[0]);
        for (auto num : nums) {
            boarder = min(abs(num), boarder);
            if (num <= 0 && k-- > 0) {
                sum -= num;
            }
            else {
                sum += num;
            }
        }
        if (k > 0 && k & 1) {
            sum -= 2 * boarder;
        }
        return sum;
    }
};
