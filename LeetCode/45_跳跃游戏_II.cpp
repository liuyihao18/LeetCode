// 45_ÌøÔ¾ÓÎÏ·_II.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int jump(const vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp(n, n + 1);
        dp.front() = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (i - j <= nums[j]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp.back();
    }
};

#ifndef LEETCODE
int main() {
    Solution solution;
    cout << solution.jump({ 2,3,1,1,4 }) << endl;
    return 0;
}
#endif
