// LCP_06_ÄÃÓ²±Ò.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minCount(vector<int>& coins) {
        int count = 0;
        for (auto coin : coins) {
            count += (coin + 1) / 2;
        }
        return count;
    }
};
