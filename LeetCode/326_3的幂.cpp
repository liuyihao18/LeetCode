// 326_3的幂
#include "custom.h"
#include <cmath>
ustd

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;  // 3的任意次幂都不可能为负整数或0
        }
        if (n == 1) {
            return true;
        }
        if (n % 3 == 0) {
            return isPowerOfThree(n / 3);
        }
        else {
            return false;
        }
    }
};