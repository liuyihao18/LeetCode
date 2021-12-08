// 689_三个无重叠子数组的最大和.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(const vector<int>& nums, int k) {
        vector<int> ans;
        int sum1 = 0, maxSum1 = 0, maxSum1Index = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Index1 = 0, maxSum12Index2 = 0;
        int sum3 = 0, maxSum123 = 0;
        for (size_t i = static_cast<size_t>(2) * k; i < nums.size(); i++) {
            sum1 += nums[i - 2 * static_cast<size_t>(k)];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i < 3 * static_cast<size_t>(k) - 1) {
                continue;
            }
            if (sum1 > maxSum1) {
                maxSum1 = sum1;
                maxSum1Index = static_cast<int>(i) - 3 * k + 1;
            }
            if (maxSum1 + sum2 > maxSum12) {
                maxSum12 = maxSum1 + sum2;
                maxSum12Index1 = maxSum1Index;
                maxSum12Index2 = static_cast<int>(i) - 2 * k + 1;
            }
            if (maxSum12 + sum3 > maxSum123) {
                maxSum123 = maxSum12 + sum3;
                ans = { maxSum12Index1, maxSum12Index2, static_cast<int>(i) - 1 * k + 1 };
            }
            sum1 -= nums[i - 3 * static_cast<size_t>(k) + 1];
            sum2 -= nums[i - 2 * static_cast<size_t>(k) + 1];
            sum3 -= nums[i - 1 * static_cast<size_t>(k) + 1];
        }
        return ans;
    }
};
