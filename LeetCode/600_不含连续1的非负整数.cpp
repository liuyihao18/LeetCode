// 600_不含连续1的非负整数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31);
        dp[0] = dp[1] = 1;
        for (size_t i = 2; i < 31; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int pre = 0, res = 0;
        for (int i = 29; i >= 0; i--) {
            // n的第1位是1，因此包含两棵子树
            // 于是加上左子树（...0...），处理右子树（...1...）
            if (n >> i & 1) {
                res += dp[i + 1];
                // 如果出现两个连续的1，则不用继续处理右子树了
                if (pre == 1) {
                    break;
                }
                pre = 1;
            }
            else {
                pre = 0;
            }

            // 叶子节点额外处理
            if (i == 0) {
                ++res;
            }
        }

        return res;
    }
};
