// 2240_买钢笔和铅笔的方案数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long result = 0;
        for (int i = 0; i * cost1 <= total; i++) {
            result += (total - i * cost1) / cost2 + 1;
        }
        return result;
    }
};
