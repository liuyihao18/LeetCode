// 390_Ïû³ýÓÎÏ·.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int lastRemaining(int n) {
        int d = 1;
        int a1 = 1;
        int direction = 1;
        while (n > 1) {
            if (direction & 1) {
                a1 += d;
            }
            else {
                if (n & 1) {
                    a1 += d;
                }
            }
            n /= 2;
            d *= 2;
            direction ^= 1;
        }
        return a1;
    }
};
