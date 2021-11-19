// 397_�����滻.cpp
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
    * ̰��
    */
    int integerReplacement_BEST(int _n) {
        long long n = static_cast<long long>(_n);
        int ans = 0;
        while (n != 1) {
            if (!(n & 1)) {
                // ��ʱ n = 0x...0
                n >>= 1;
            }
            else {
                // ��ʱ n = 0x...1
                if (n != 3 && (n >> 1) & 1) {
                    // ��ʱ n = 0x...11
                    // ��1��������������һ��1
                    n++;
                }
                else {
                    // ��ʱ n = 0x...01
                    // ��һ������������1
                    n--;
                }
            }
            ans++;
        }
        return ans;
    }
};
