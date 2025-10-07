// 1799_N次操作后的最大分数和.cpp
#include "stdafx.h"
ustd

// TLE
class Solution {
    int gcd(int a, int b) {
        while (b > 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    int dfs(int epoch, size_t n, const vector<vector<int>>& table, vector<bool>& visited) {
        if (epoch > n) {
            return 0;
        }
        int result = 0;
        for (size_t i = 0; i + 1 < n; i++) {
            if (!visited[i]) {
                for (size_t j = i + 1; j < n; j++) {
                    if (!visited[j]) {
                        visited[i] = true;
                        visited[j] = true;
                        result = max(result, epoch * table[i][j] + dfs(epoch + 1, n, table, visited));
                        visited[i] = false;
                        visited[j] = false;
                    }
                }
            }
        }
        return result;
    }
public:
    int maxScore(vector<int>& nums) {
        size_t n = nums.size();
        vector<vector<int>> table(n, vector<int>(n, 0));
        for (size_t i = 0; i + 1 < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                table[i][j] = gcd(nums[i], nums[j]);
            }
        }
        vector<bool> visited(n, false);
        return dfs(1, n, table, visited);
    }
}; 

/*
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        vector<int> dp(1 << m, 0);
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << m;
        for (int s = 1; s < all; ++s) {
            int t = __builtin_popcount(s);
            if (t & 1) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    for (int j = i + 1; j < m; ++j) {
                        if ((s >> j) & 1) {
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }
        return dp[all - 1];
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/maximize-score-after-n-operations/solutions/2028201/n-ci-cao-zuo-hou-de-zui-da-fen-shu-he-by-i9k5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
