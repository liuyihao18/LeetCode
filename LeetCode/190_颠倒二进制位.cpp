// 190_颠倒二进制位.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int reverseBits(int n) {
        int result{};
        for (int i{ 0 }; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        return result;
    }
};
