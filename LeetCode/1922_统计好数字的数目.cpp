// 1922_统计好数字的数目.cpp
#include "stdafx.h"
ustd

class Solution {
private:
    long long remainder { static_cast<long long>(1e9 + 7) };
    long long _countGoodNumbers(long long n) {
        if (n == 1) {
            return 5LL;
        }
        if (n == 2) {
            return 5LL * 4;
        }
        if (n == 3) {
            return 5LL * 4 * 5;
        }
        long long half = n >> 1;
        long long result = 1;
        if (half & 1) {
            long long temp = _countGoodNumbers(half - 1);
            result *= (temp * temp) % remainder * 20;
        }
        else {
            long long temp = _countGoodNumbers(half);
            result *= (temp * temp) % remainder;
        }
        if (n & 1) {
            result *= 5LL;
        }
        return result % remainder;
    }
public:
    int countGoodNumbers(long long n) {
        return static_cast<int>(_countGoodNumbers(n));
    }
};
