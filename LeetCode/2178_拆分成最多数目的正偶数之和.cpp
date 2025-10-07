// 2178_拆分成最多数目的正偶数之和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1) return {};
        vector<long long> result;
        long long temp = 2;
        while (finalSum > 2 * temp) {
            result.push_back(temp);
            finalSum -= temp;
            temp += 2;
        }
        if (finalSum > 0) result.push_back(finalSum);
        return result;
    }
};
