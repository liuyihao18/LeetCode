// 3405_统计恰好有K个相等相邻元素的数组数目.cpp
#include "custom.h"
ustd

const long long MOD = static_cast<long long>(1e9 + 7);

// 正解要组合数学阿弥陀佛，不过又熟练了一下矩阵快速幂
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        // dp[i][j] 长度为 i 的数组且有 j 个下标满足条件
        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * (m - 1)
        vector<long long> dp(k + 1, 0);
        dp[0] = m;
        for (size_t i = 2; i <= n; i++) {
            vector<long long> temp = dp;
            dp[0] = (temp[0] * (m - 1)) % MOD;
            for (size_t j = 1; j <= k; j++) {
                dp[j] = (temp[j - 1] + (temp[j] * (m - 1)) % MOD) % MOD;
            }
        }
        return dp[k];
    }
};

int main() {
    Solution solution;
    int n = 10, m = 10, k = 0;
    cout << solution.countGoodArrays(n, m, k) << endl;
    return 0;
}
