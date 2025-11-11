// 474_一和零.cpp
#include "stdafx.h"
ustd

// 永远不会写背包问题的我
class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = static_cast<int>(str.length());
        for (int i = 0; i < length; i++) {
            zerosOnes[static_cast<size_t>(str[i]) - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = static_cast<int>(strs.size());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], dp[static_cast<size_t>(j) - zeros][static_cast<size_t>(k) - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/ones-and-zeroes/solutions/814806/yi-he-ling-by-leetcode-solution-u2z2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
