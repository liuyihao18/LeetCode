// 1780_�ж�һ�������Ƿ���Ա�ʾ�������ݵĺ�.cpp
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
