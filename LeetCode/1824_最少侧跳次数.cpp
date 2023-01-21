// 1824_最少侧跳次数.cpp
#include "custom.h"
ustd

class Solution {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = static_cast<int>(obstacles.size()) - 1;
        vector<int> d = { 1, 0, 1 };
        for (int i = 1; i <= n; i++) {
            int minCnt = inf;
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                }
                else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/minimum-sideway-jumps/solutions/2070379/zui-shao-ce-tiao-ci-shu-by-leetcode-solu-3y2g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
