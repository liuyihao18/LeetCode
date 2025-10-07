// 441_≈≈¡–”≤±“.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int arrangeCoins(int n) {
        long long delta = static_cast<long long>(sqrt(1L + 8L * n));
        return static_cast<int>((delta - 1) / 2);
    }
};