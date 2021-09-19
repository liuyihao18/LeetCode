// 650_只有两个键的键盘.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                return i + minSteps(n / i);
            }
        }
        return n + minSteps(1);
    }
};