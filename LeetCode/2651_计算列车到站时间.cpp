// 2651_�����г���վʱ��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
