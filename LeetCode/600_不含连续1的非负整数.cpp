// 600_��������1�ķǸ�����.cpp
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
            // n�ĵ�1λ��1����˰�����������
            // ���Ǽ�����������...0...����������������...1...��
            if (n >> i & 1) {
                res += dp[i + 1];
                // �����������������1�����ü���������������
                if (pre == 1) {
                    break;
                }
                pre = 1;
            }
            else {
                pre = 0;
            }

            // Ҷ�ӽڵ���⴦��
            if (i == 0) {
                ++res;
            }
        }

        return res;
    }
};
