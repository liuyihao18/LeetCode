// 3622_ÅÐ¶ÏÕû³ýÐÔ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool checkDivisibility(const int n) {
        int num = n, digitSum = 0, digitProduct = 1;
        while (num > 0)
        {
            const int digit = num % 10;
            digitSum += digit;
            digitProduct *= digit;
            num /= 10;
        }
        return n % (digitSum + digitProduct) == 0;
    }
};
