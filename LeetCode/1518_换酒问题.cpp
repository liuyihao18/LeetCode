// 1518_��������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            res += empty / numExchange;
            empty = empty % numExchange + empty / numExchange;
        }
        return res;
    }
};
