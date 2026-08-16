// 3754_连接非零数字并乘以其数字和_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long sumAndMultiply(int n) {
        const string str = to_string(n);
        long long x = 0;
        long long sum = 0;
        for (const char c : str) {
            const int digit = c - '0';
            if (digit != 0) {
                x = x * 10 + digit;
                sum += digit;
            }
        }
        return x * sum;
    }
};
