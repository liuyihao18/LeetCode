// 829_连续整数求和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int result = 0;
        int upper = (-1 + static_cast<int>(sqrt(1LL + 8LL * n))) / 2;
        for (int i = 1; i <= upper; i++) {
            int remainder = (i & 1) ? 0 : i / 2;
            if (n % i == remainder) result++;
        }
        return result;
    }
};
