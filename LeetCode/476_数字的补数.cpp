// 476_Êı×ÖµÄ²¹Êı.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findComplement(int num) {
        int highest_bit = 31;
        for (; highest_bit >= 0; highest_bit--) {
            if (num & (1 << highest_bit)) {
                break;
            }
        }
        int mask = 1;
        for (int i = 0; i < highest_bit; i++) {
            mask <<= 1;
            mask |= 1;
        }
        return ~num & mask;
    }
};
