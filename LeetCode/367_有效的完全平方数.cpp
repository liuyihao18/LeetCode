// 367. 有效的完全平方数
#include "custom.h"
ustd

class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long long i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
};