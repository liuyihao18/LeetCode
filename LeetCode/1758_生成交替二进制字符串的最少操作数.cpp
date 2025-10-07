// 1758_生成交替二进制字符串的最少操作数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minOperations(string s) {
        int result = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (i & 1 && s[i] != '0') {
                result++;
            }
            else if (!(i & 1) && s[i] != '1') {
                result++;
            }
        }
        return min(result, static_cast<int>(s.size()) - result);
    }
};
