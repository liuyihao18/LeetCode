// 1691_堆叠长方体的最大高度.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = static_cast<int>(cuboids.size());
        for (auto& v : cuboids) {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
            });
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/maximum-height-by-stacking-cuboids/solutions/2013994/dui-die-chang-fang-ti-de-zui-da-gao-du-b-17qg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
