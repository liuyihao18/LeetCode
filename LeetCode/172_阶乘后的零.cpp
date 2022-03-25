// 172_½×³ËºóµÄÁã.cpp
#include "custom.h"
ustd

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        int base = 5;
        while (base <= n) {
            result += n / base;
            base *= 5;
        }
        return result;
    }
};
