// 1833_雪糕的最大数量.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
    	const size_t n = costs.size();
        size_t i = 0;
    	int result = 0;
        while (i < n && costs[i] <= coins)
        {
            result++;
            coins -= costs[i];
            i++;
        }
        return result;
    }
};
