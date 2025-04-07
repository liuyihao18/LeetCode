// 416_分割等和子集.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum >> 1;
        int maximum = *max_element(nums.begin(), nums.end());
        if (maximum > target) {
            return false;
        }
        size_t n = nums.size();
        // dp[i][j]表示下标0...i的数中选择若干个数是否恰好可以等于j
        vector<vector<bool>> dp(n, vector<bool>(target + 1)); 
        for (size_t i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        // dp[i][j]表示下标0...i的物品且此时背包容量为j能达到的最大价值
        dp[0][nums[0]] = true;
        for (size_t i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum >> 1;
        int maximum = *max_element(nums.begin(), nums.end());
        if (maximum > target) {
            return false;
        }
        set<int> s;
        s.insert(0);
        for (auto num : nums) {
            vector<int> temp(s.begin(), s.end());
            transform(temp.begin(), temp.end(), temp.begin(), [&](int n) { return (n + num) % (target + 1); });
            s.insert(temp.begin(), temp.end());
        }
        return s.count(target);
    }
};
*/
