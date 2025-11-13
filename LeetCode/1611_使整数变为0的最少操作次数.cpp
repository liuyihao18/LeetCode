// 1611_使整数变为0的最少操作次数.cpp
#include "stdafx.h"
ustd

class Solution {
    map<int, int> m;
public:
    int minimumOneBitOperations(int n) {
        if (m.count(n)) {
            return m[n];
        }
        if (n == 0) {
            return m[n] = 0;
        }
        if (n == 1) {
            return m[n] = 1;
        }
        if (n == 2) {
            return m[n] = 3;
        }
        if (n == 3) {
            return m[n] = 2;
        }
        if (n == 4) {
            // 100 -> 101 -> 111 -> 110 -> 010 -> 011 -> 001 -> 000
            return m[n] = 7;
        }
        if (n == 5) {
            // 101 -> 111 -> 110 -> 010 -> 011 -> 001 -> 000
            return m[n] = 6;
        }
        if (n == 6) {
            // 110 -> 010 -> 011 -> 001 -> 000
            return m[n] = 4;
        }
        if (n == 7) {
            // 111 -> 110 -> 010 -> 011 -> 001 -> 000
            return m[n] = 5;
        }
        // dp[32][2] 下次再做
        return m[n] = 0;
    }
};
