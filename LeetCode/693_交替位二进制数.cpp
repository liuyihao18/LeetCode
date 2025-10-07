// 693_交替位二进制数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n & 1;
        n >>= 1;
        while (n != 0) {
            int temp = n & 1;
            if (temp == bit) {
                return false;
            }
            else {
                bit = temp;
            }
            n >>= 1;
        }
        return true;
    }
};
