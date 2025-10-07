// 871_��ͼ��ʹ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        size_t n = stations.size();
        vector<long> dp(n + 1);
        dp[0] = startFuel;
        for (size_t i = 0; i < n; i++) {
            for (int j = static_cast<int>(i); j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[static_cast<size_t>(j) + 1] = 
                        max(dp[static_cast<size_t>(j) + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (size_t i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return static_cast<int>(i);
            }
        }
        return -1;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/minimum-number-of-refueling-stops/solution/zui-di-jia-you-ci-shu-by-leetcode-soluti-nmga/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
