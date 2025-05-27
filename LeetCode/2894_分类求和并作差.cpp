// 2894_分类求和并作差.cpp
#include "custom.h"
ustd

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                num1 += i;
            }
            else {
                num2 += i;
            }
        }
        return num1 - num2;
    }
};
