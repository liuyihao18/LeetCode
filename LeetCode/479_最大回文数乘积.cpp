// 479_最大回文数乘积.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = static_cast<int>(pow(10, n)) - 1;
        for (int left = upper;; --left) {
            long long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10;
            }
            for (long long x = upper; x * x >= p; x--) {
                if (p % x == 0) {
                    return p % 1337;
                }
            }
        }
        int result[] = {9,987,123,597,677,1218,877,475};
        return result[n - 1];
    }
};
