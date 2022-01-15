// 1716_计算力扣银行的钱.cpp
#include "custom.h"
ustd

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        const int _money = (1 + 7) * 7 / 2;
        int money = weeks * _money + weeks * (weeks - 1) * 7 / 2;
        return money + (2 * weeks + days + 1) * days / 2;
    }
};
