// 926_���ַ�����ת����������.cpp
#include "stdafx.h"
ustd

// TODO: ����DP
class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        // dp[i][j]��ʾ����Ϊi���ַ������һ���ַ���ת��j�������������С����
        int dp0 = 0, dp1 = 0;
        for (char c : s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            }
            else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/flip-string-to-monotone-increasing/solution/jiang-zi-fu-chuan-fan-zhuan-dao-dan-diao-stjd/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
