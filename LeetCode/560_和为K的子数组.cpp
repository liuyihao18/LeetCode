// 560_和为K的子数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t n = nums.size();
        unordered_map<int, int> preSum;
        int sum = 0;
        preSum[0] = 1;
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            sum += nums[i];
            if (preSum.count(sum - k)) {
                ans += preSum[sum - k];
            }
            preSum[sum]++;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (size_t i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            if (dp[i][i] == k) {
                ans++;
            }
        }
        for (size_t j = 1; j <= n; j++) {
            for (size_t i = 0; i + j < n; i++) {
                dp[i][i + j] = dp[i][i + j - 1] + nums[i + j];
                if (dp[i][i + j] == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
*/
