// 2544_�������ֺ�.cpp
#include "custom.h"
ustd

class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int sign = 1;
        int result = 0;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            result += sign * *iter;
            sign = -sign;
        }
        return result;
    }
};
