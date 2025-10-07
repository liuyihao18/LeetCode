// 1304_和为零的N个不同整数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> results;
        if (n & 1) {
            results.push_back(0);
            n--;
        }
        for (int i = 1; i <= n / 2; i++) {
            results.push_back(i);
            results.push_back(-i);
        }
        return results;
    }
};
