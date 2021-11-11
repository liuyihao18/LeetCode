// 629_K�����������.cpp
#include "custom.h"
ustd

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    /**
    * f[i][j] ��ʾʹ����ֵ[1,i]���ճ����������ǡ��Ϊj�����������
    * �����i��������λ��Ϊk������ֵi�����������ֵ�����ɵ��������Ϊ(i-1)-k��
    * �����i����ص����������Ϊj-(i-1-k)��
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
