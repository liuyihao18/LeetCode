// 2180_统计各位数字之和为偶数的整数个数.cpp
#include "custom.h"
ustd

class Solution {
    /*
    bool isEven(int num) {
        string str = to_string(num);
        int result = 0;
        for (auto c : str) {
            result += c - '0';
        }
        return !(result & 1);
    }
     */
    bool isEven(int num) {
        int result = 0;
        while (num > 0) {
            result += num % 10;
            num /= 10;
        }
        return !(result & 1);
    }
public:
    int countEven(int num) {
        int result = 0;
        for (int i = 2; i <= num; i++) {
            if (isEven(i)) {
                result++;
            }
        }
        return result;
    }
};
