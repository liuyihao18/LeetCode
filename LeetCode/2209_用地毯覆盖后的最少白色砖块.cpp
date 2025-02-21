// 2209_用地毯覆盖后的最少白色砖块.cpp
#include "custom.h"
ustd

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        size_t n = floor.size();
        // d[i][j]表示在前i个砖块上使用了j个地毯后，最少有多少未被覆盖的白色砖块
        vector<vector<int>> dp(n + 1, vector<int>(numCarpets + 1, INT_MAX));
        for (size_t j = 0; j <= numCarpets; j++) {
            dp[0][j] = 0;
        }
        for (size_t i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (floor[i - 1] == '1');
        }
        for (size_t i = 1; i <= n; i++) {
            for (size_t j = 1; j <= numCarpets; j++) {
                dp[i][j] = dp[i - 1][j] + (floor[i - 1] == '1');
                dp[i][j] = min(dp[i][j], dp[max(static_cast<int>(i) - carpetLen, 0)][j - 1]);
            }
        }
        return dp[n][numCarpets];
    }
};
