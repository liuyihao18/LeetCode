// 3756_连接非零数字并乘以其数字和_II.cpp
#include "stdafx.h"
ustd

class Solution {
private:
    static const long long MOD = static_cast<long long>(1e9 + 7);
    static long long qpow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) {
                r = r * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return r;
    }
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long > prefixX = { 0 }, prefixSum = { 0 };
        vector<int> prefixCnt = { 0 };
        long long x = 0, sum = 0;
        int cnt = 0;
        for (char c : s) {
            const int digit = c - '0';
            if (digit) {
                x = (x * 10 + digit) % MOD;
                sum = (sum + digit) % MOD;
                cnt++;
            }
            prefixX.push_back(x);
            prefixSum.push_back(sum);
            prefixCnt.push_back(cnt);
        }
        vector<int> results;
        for (const vector<int>& query : queries) {
            const int l = query[0];
            const int r = query[1] + 1;
            const int length = prefixCnt[r] - prefixCnt[l];
            const long long x = (prefixX[r] - prefixX[l] * qpow(10, length) % MOD + MOD) % MOD;
            const long long sum = prefixSum[r] - prefixSum[l];
            results.push_back(static_cast<int>(x * sum % MOD));
        }
        return results;
    }
};
