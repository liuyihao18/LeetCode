// 629_K个逆序对数组.cpp
#include "custom.h"
ustd

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    /**
    * f[i][j] 表示使用数值[1,i]，凑成逆序对数量恰好为j的数组个数，
    * 假设第i个数所在位置为k，则数值i（数组中最大值）构成的逆序对数为(i-1)-k，
    * 因此与i不相关的逆序对数量为j-(i-1-k)。
    * f[i][j] = \sum_{k=1}^{i}{f[i-1][j-(i-k)]} = \sum_{k=0}^{i-1}{f[i-1][j-k]}
    * f[i][j] = f[i][j-1] - f[i-1][j-i] + f[i-1][j]
    */
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(2, vector<int>(static_cast<size_t>(k) + 1));
        f[0][0] = 1;
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 0; j <= k; ++j) {
                size_t cur = i & 1, prev = cur ^ 1;
                f[cur][j] = (j - 1 >= 0 ? f[cur][j - 1] : 0) - (j - i >= 0 ? f[prev][j - i] : 0) + f[prev][j];
                if (f[cur][j] >= mod) {
                    f[cur][j] -= mod;
                }
                else if (f[cur][j] < 0) {
                    f[cur][j] += mod;
                }
            }
        }
        return f[n & 1][k];
    }
};
