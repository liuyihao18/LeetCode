// 813_���ƽ��ֵ�͵ķ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<double> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = prefix[i] / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = n; i >= j; i--) {
                for (int x = j - 1; x < i; x++) {
                    dp[i] = max(dp[i], dp[x] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n];
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/largest-sum-of-averages/solutions/1993132/zui-da-ping-jun-zhi-he-de-fen-zu-by-leet-09xt/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
