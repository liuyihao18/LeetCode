// 808_分汤.cpp
#include "custom.h"
ustd

class Solution {
public:
    double soupServings(int n) {
        n = static_cast<int>(ceil(n * 1.0 / 25));
        if (n >= 179) {
            return 1.0;
        }
        memo = vector<vector<double>>(n + 1, vector<double>(n + 1));
        return dfs(n, n);
    }

    double dfs(int a, int b) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        else if (a <= 0) {
            return 1;
        }
        else if (b <= 0) {
            return 0;
        }
        if (memo[a][b] > 0) {
            return memo[a][b];
        }
        memo[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) + dfs(a - 1, b - 3));
        return memo[a][b];
    }
private:
    vector<vector<double>> memo;
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/soup-servings/solutions/1981704/fen-tang-by-leetcode-solution-0yxs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
