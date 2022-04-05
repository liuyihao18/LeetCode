// 762_二进制表示中质数个计算置位.cpp
#include "custom.h"
ustd

constexpr int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19 };

class Solution {
    bool countPrimeSetBit(int num) {
        int count = 0;
        while (num != 0) {
            count += num & 1;
            num >>= 1;
        }
        return find(begin(prime), end(prime), count) != end(prime);
    }
public:
    int countPrimeSetBits(int left, int right) {
        int result = 0;
        for (int i = left; i <= right; i++) {
            if (countPrimeSetBit(i)) {
                result++;
            }
        }
        return result;
    }
};
