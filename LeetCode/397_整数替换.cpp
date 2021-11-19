// 397_整数替换.cpp
#include "custom.h"
ustd

class Solution {
    unordered_map<long long, size_t> dp;
    void _replace(long long n, size_t times) {
        if (times > dp[1]) {
            return;
        }
        dp[n] = min(dp[n], times);
        if (n == 1) {
            return;
        }
        if (n & 1) {
            _replace(n + 1, times + 1);
            _replace(n - 1, times + 1);
        }
        else {
            _replace(n >> 1, times + 1);
        }
    }
public:
    int integerReplacement(int n) {
        dp[1] = SIZE_MAX;
        _replace(static_cast<long long>(n), 0);
        return static_cast<int>(dp[1]);
    }
    /**
    * 贪心
    */
    int integerReplacement_BEST(int _n) {
        long long n = static_cast<long long>(_n);
        int ans = 0;
        while (n != 1) {
            if (!(n & 1)) {
                // 此时 n = 0x...0
                n >>= 1;
            }
            else {
                // 此时 n = 0x...1
                if (n != 3 && (n >> 1) & 1) {
                    // 此时 n = 0x...11
                    // 加1可以消除连续的一段1
                    n++;
                }
                else {
                    // 此时 n = 0x...01
                    // 减一可以消除最后的1
                    n--;
                }
            }
            ans++;
        }
        return ans;
    }
};
