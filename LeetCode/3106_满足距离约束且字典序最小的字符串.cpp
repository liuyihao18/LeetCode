// 3106_�������Լ�����ֵ�����С���ַ���.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string getSmallestString(string s, int k) {
        for (size_t i = 0; i < s.size() && k > 0; i++) {
            int minDis = min((s[i] - 'a') % 26, ('a' + 26 - s[i]) % 26);
            if (minDis <= k) {
                s[i] = 'a';
                k -= minDis;
            }
            else {
                s[i] = s[i] - k;
                k = 0;
            }
        }
        return s;
    }
};
