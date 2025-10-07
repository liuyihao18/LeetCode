// 29_БЅКэПаіэ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == INT_MIN) {
            return 1;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        bool negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long long long_dividend = dividend;
        long_dividend = abs(long_dividend);
        long long long_divisor = divisor;
        long_divisor = abs(long_divisor);
        if (long_divisor > long_dividend) {
            return 0;
        }
        long long result = 0;
        int count = 0;
        long long long_divisor_copy = long_divisor;
        while (long_divisor_copy <= long_dividend) {
            long_divisor_copy <<= 1;
            count++;
        }
        for (--count; count >= 0; --count) {
            if (long_dividend >= (long_divisor << count)) {
                result +=  (1LL << count);
                long_dividend -= (long_divisor << count);
            }
        }
        if (negative) {
            result = -result;
        }
        return static_cast<int>(result);
    }
};