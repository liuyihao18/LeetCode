// 2335_装满杯子需要的最短总时长.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int result = 0;
        sort(amount.begin(), amount.end());
        while (amount[2] > 0) {
            amount[2]--;
            if (amount[0] > 0) {
                amount[0]--;
            }
            else if (amount[1] > 0) {
                amount[1]--;
            }
            result++;
            sort(amount.begin(), amount.end());
        }
        return result;
    }
};
