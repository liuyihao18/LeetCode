// 2144_打折购买糖果的最小开销.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost);
        int ans = 0, count = 1;
        for (const int c : views::reverse(cost))
        {
            ans += c * (count % 3 == 0 ? 0 : 1);
            count++;
        }
        return ans;
    }
};