// 441_≈≈¡–”≤±“.cpp
#include "custom.h"
ustd

class Solution {
public:
    int arrangeCoins(int n) {
        long long delta = static_cast<long long>(sqrt(1L + 8L * n));
        return static_cast<int>((delta - 1) / 2);
    }
};