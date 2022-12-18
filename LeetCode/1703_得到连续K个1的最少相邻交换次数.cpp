// 1703_得到连续K个1的最少相邻交换次数
#include "custom.h"
ustd

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> g;
        vector<int> preSum(1, 0);
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == 1) {
                g.emplace_back(i - static_cast<int>(g.size()));
                preSum.emplace_back(preSum.back() + g.back());
            }
        }
        int m = static_cast<int>(g.size()), res = INT_MAX;
        for (int i = 0; i <= m - k; i++) {
            int mid = i + k / 2;
            res = min(res, (1 - k % 2) * g[mid] + \
                (preSum[i + k] - preSum[mid + 1]) - \
                (preSum[mid] - preSum[i]));
        }
        return res;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/minimum-adjacent-swaps-for-k-consecutive-ones/solutions/2024008/de-dao-lian-xu-k-ge-1-de-zui-shao-xiang-mk5ws/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
