// 741_摘樱桃.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = static_cast<int>(grid.size());
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][0] = grid[0][0];
        size_t const1 = 1;
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) {
                for (int x2 = min(k, n - 1); x2 >= x1; --x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][x2] = INT_MIN;
                        continue;
                    }
                    int res = f[x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[x1 - const1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[x1][x2 - const1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[x1 - const1][x2 - const1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[x1][x2] = res;
                }
            }
        }
        return max(f.back().back(), 0);
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
