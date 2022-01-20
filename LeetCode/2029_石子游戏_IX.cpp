// 2029_石子游戏_IX.cpp
#include "custom.h"
ustd

class Solution {
public:
    /*
    作者：LeetCode - Solution
    链接：https://leetcode-cn.com/problems/stone-game-ix/solution/gong-shui-san-xie-fen-qing-kuang-tao-lun-h1oa/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val : stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            }
            else if (type == 1) {
                ++cnt1;
            }
            else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};
