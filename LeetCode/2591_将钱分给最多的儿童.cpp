// 2591_将钱分给最多的儿童.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) return -1;
        int temp = children * 8 - money;
        if (temp == 4) return children - 2;
        if (temp < 0) return children - 1;
        return (money - children) / 7;
    }
};
