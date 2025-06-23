// 2929_给小朋友们分糖果_II.cpp
#include "custom.h"
ustd

class Solution {
    int distributeCandiesTwo(int n, int limit) {
        if (n > 2 * limit) {
            return 0;
        }
        // min + limit <= n => min <= n - limit
        // max = min(limit, n)
        return min(limit, n) - max(0, n - limit) + 1;
    }
    int distributeCandiesOne(int n, int limit) {
        if (n < 0 || n > limit) {
            return 0;
        }
        return 1;
    }
public:
    long long distributeCandies(int n, int limit) {
        long long result = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            result += static_cast<long long>(distributeCandiesTwo(n - i, limit));
        }
        return result;
    }
};
