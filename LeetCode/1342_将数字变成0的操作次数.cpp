// 1342_将数字变成0的操作次数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;
        while (num) {
            if (num & 1) {
                num--;
            }
            else {
                num >>= 1;
            }
            result++;
        }
        return result;
        /* 
        return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
        */
    }
};
