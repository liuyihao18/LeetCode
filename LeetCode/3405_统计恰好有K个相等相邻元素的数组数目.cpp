// 3405_ͳ��ǡ����K���������Ԫ�ص�������Ŀ.cpp
#include "custom.h"
ustd

const long long MOD = static_cast<long long>(1e9 + 7);

// ����Ҫ�����ѧ�����ӷ𣬲�����������һ�¾��������
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        // dp[i][j] ����Ϊ i ���������� j ���±���������
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
