// 1780_判断一个数字是否可以表示成三的幂的和.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers;
        int base = 1;
        while (base < 10000000) {
            powers.push_back(base);
            base *= 3;
        }
        while (n > 0) {
            auto iter = upper_bound(powers.begin(), powers.end(), n);
            if (iter == powers.begin()) {
                break;
            }
            --iter;
            n -= *iter;
            powers.erase(iter);
        }
        return n == 0;
    }
}; 
