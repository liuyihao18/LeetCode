// ½£Ö¸_Offer_II_091_·ÛË¢·¿×Ó.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> total(3);
        for (size_t i = 0; i < costs.size(); i++) {
            vector<int> newTotal(3);
            newTotal[0] = min(total[1] + costs[i][0], total[2] + costs[i][0]);
            newTotal[1] = min(total[0] + costs[i][1], total[2] + costs[i][1]);
            newTotal[2] = min(total[0] + costs[i][2], total[1] + costs[i][2]);
            total = newTotal;
        }
        return min({ total[0], total[1], total[2] });
    }
};
