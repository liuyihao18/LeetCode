// 2651_计算列车到站时间.cpp
#include "custom.h"
ustd

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
