// 467_�����ַ�����Ψһ�����ַ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int k = 0;
        for (size_t i = 0; i < p.length(); ++i) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) { // �ַ�֮��Ϊ 1 �� -25
                ++k;
            }
            else {
                k = 1;
            }
            // ״̬Ϊ����ĸx��β���ַ�����������
            dp[static_cast<size_t>(p[i]) - 'a'] = max(dp[static_cast<size_t>(p[i]) - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/unique-substrings-in-wraparound-string/solution/huan-rao-zi-fu-chuan-zhong-wei-yi-de-zi-ndvea/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
