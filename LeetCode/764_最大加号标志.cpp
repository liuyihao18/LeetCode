// 764_最大加号标志.cpp
#include "custom.h"
ustd

class Solution {
    bool satisfy(const vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x - k + 1; i <= x + k - 1; i++) {
            if (grid[i][y] == 0) return false;
        }
        for (int j = y - k + 1; j <= y + k - 1; j++) {
            if (grid[x][j] == 0) return false;
        }
        return true;
    }
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (const auto& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }
        int max = static_cast<int>(n + 1) / 2;
        for (int k = max; k >= 1; k--) {
            for (int x = k - 1; x + k - 1 < n; x++) {
                for (int y = k - 1; y + k - 1 < n; y++) {
                    if (satisfy(grid, x, y, k)) return k;
                }
            }
        }
        return 0;
    }
};

/*
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        unordered_set<int> banned;
        for (auto&& vec : mines) {
            banned.emplace(vec[0] * n + vec[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            // left
            for (int j = 0; j < n; j++) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            // right
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            // up
            for (int j = 0; j < n; j++) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
            }
            count = 0;
            // down
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/largest-plus-sign/solutions/1956480/zui-da-jia-hao-biao-zhi-by-leetcode-solu-jirt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/