// 357_ͳ�Ƹ�λ���ֶ���ͬ�����ָ���.cpp
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
