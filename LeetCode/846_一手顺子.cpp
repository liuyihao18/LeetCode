// 846_Ò»ÊÖË³×Ó.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool isNStraightHand(const vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, size_t> handCount;
        for (auto a : hand) {
            handCount[a]++;
        }
        for (auto iter = handCount.begin(); iter != handCount.end();) {
            if (!iter->second) {
                iter = handCount.erase(iter);
                continue;
            }
            int a = iter->first;
            map<int, size_t>::iterator pos = iter;
            for (int i = 0; i < groupSize; i++, pos++) {
                if (pos == handCount.end()) {
                    return false;
                }
                else {
                    if (pos->first != a + i || !pos->second) {
                        return false;
                    }
                    else {
                        pos->second--;
                    }
                }
            }
        }
        return true;
    }
};
