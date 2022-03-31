// 728_×Ô³ýÊý.cpp
#include "custom.h"
ustd

class Solution {
    bool isSelfDividingNumber(int num) {
        int temp = num;
        while (temp > 0) {
            if (temp % 10 == 0) {
                return false;
            }
            else {
                if (num % (temp % 10)) {
                    return false;
                }
            }
            temp /= 10;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};
