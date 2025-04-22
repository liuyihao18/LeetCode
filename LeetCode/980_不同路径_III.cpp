// 980_不同路径_III.cpp
#include "custom.h"
ustd

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = static_cast<int>(grid.size()), c = static_cast<int>(grid[0].size());
        int si = 0, sj = 0, n = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    n++;
                }
                else if (grid[i][j] == 1) {
                    n++;
                    si = i;
                    sj = j;
                }
            }
        }

        function<int(int, int, int)> dfs = [&](int i, int j, int n) -> int {
            if (grid[i][j] == 2) {
                if (n == 0) {
                    return 1;
                }
                return 0;
            }

            int t = grid[i][j], res = 0;
            grid[i][j] = -1;
            vector<array<int, 2>> dir({ {-1, 0}, {1, 0}, {0, -1}, {0, 1} });
            for (auto& [di, dj] : dir) {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && \
                    (grid[ni][nj] == 0 || grid[ni][nj] == 2)) {
                    res += dfs(ni, nj, n - 1);
                }
            }
            grid[i][j] = t;
            return res;
        };
        return dfs(si, sj, n);
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/unique-paths-iii/solutions/2365866/bu-tong-lu-jing-iii-by-leetcode-solution-cndw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
