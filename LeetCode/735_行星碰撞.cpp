// 735_行星碰撞.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> l(asteroids.begin(), asteroids.end());
        auto iter1 = l.begin();
        while (iter1 != l.end()) {
            while (iter1 != l.end() && *iter1 > 0) {
                ++iter1;
            }
            if (iter1 == l.begin()) {
                ++iter1;
                continue;
            }
            auto iter2 = prev(iter1);
            if (*iter2 < 0) {
                ++iter1;
                continue;
            }
            if (iter1 != l.end()) {
                if (-*iter1 < *iter2) {
                    iter1 = l.erase(iter1);
                }
                else if (-*iter1 > *iter2) {
                    iter2 = l.erase(iter2);
                }
                else {
                    iter1 = l.erase(iter1);
                    iter2 = l.erase(iter2);
                }
            }
        }
        return vector<int>(l.begin(), l.end());
    }
    // 实际上用栈模拟做更容易
};
