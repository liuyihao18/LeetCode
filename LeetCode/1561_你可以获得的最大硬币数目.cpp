// 1561_����Ի�õ����Ӳ����Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = static_cast<int>(piles.size()) / 3;
        sort(piles.begin(), piles.end());
        int coins = 0;
        for (int i = 0; i < n; i++) {
            coins += piles[static_cast<size_t>(n + 2 * i)];
        }
        return coins;
    }
};
