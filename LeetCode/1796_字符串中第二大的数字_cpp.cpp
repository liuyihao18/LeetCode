// 1796_字符串中第二大的数字.cpp
#include "custom.h"
ustd

class Solution {
public:
    int secondHighest(string s) {
        int max1 = -1;
        int max2 = -1;
        for (auto c : s) {
            if (isdigit(c)) {
                int num = c - '0';
                if (num > max1) {
                    max2 = max1;
                    max1 = num;
                }
                else if (num < max1 && num > max2) {
                    max2 = num;
                }
            }
        }
        return max2;
    }
};
