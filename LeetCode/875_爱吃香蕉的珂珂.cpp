// 875_°®³ÔÏã½¶µÄçæçæ.cpp
#include "custom.h"
ustd

class Solution {
    bool canEat(const vector<int>& piles, int h, int speed) {
        for (auto pile : piles) {
            if ((h -= (pile + speed - 1) / speed) < 0) {
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end());
        while (minSpeed < maxSpeed) { // [minSpeed, maxSpeed]
            int middleSpeed = (minSpeed + maxSpeed) / 2;
            if (canEat(piles, h, middleSpeed)) {
                maxSpeed = middleSpeed;
            }
            else {
                minSpeed = middleSpeed + 1;
            }
        }
        return maxSpeed;
    }
};
