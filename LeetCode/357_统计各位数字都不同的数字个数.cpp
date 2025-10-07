// 357_统计各位数字都不同的数字个数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 0;
        for (; n > 0; n--) {
            int temp = 9;
            for (int i = 1; i < n; i++) {
                temp *= (10 - i);
            }
            result += temp;
        }
        result++; // n = 0
        return result;
    }
};
