// 368_最大整除子集.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1); // dp[i]表示以nums[i]开始的整除链的最长长度
        vector<size_t> next(n, -1);
        for (size_t i = n - 1; i != -1; i--) {
            for (size_t j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        next[i] = j;
                    }
                }
            }
        }
        size_t index = max_element(dp.begin(), dp.end()) - dp.begin();
        vector<int> result;
        for (; index < n; index = next[index]) {
            result.push_back(nums[index]);
        }
        return result;
    }
};
