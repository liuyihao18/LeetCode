// 3364_最小正和子数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        const size_t n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (size_t i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int result = INT_MAX;
        for (int m = l; m <= r; m++) {
            for (size_t i = 0; i + m <= n; i++) {
                if (const int sum = prefixSum[i + m] - prefixSum[i];
                    sum > 0)
                {
                    result = min(result, sum);
                }
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
