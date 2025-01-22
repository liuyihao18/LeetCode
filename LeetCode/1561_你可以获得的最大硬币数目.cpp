// 1561_你可以获得的最大硬币数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(piles.begin(), piles.end());
        int coins = 0;
        for (int i = 0; i < n; i++) {
            coins += piles[static_cast<size_t>(n + 2 * i)];
        }
        return coins;
    }
};
