// 2576_求出最多标记下标.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        int l = 0, r = n / 2;
        auto check = [&](int m) {
            for (int i = 0; i < m; i++) {
                if (nums[i] * 2 > nums[n - m + i]) {
                    return false;
                }
            }
            return true;
        };
        while (l < r) {
            int m = (l + r + 1) >> 1;
            if (check(m)) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        return l * 2;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/solutions/2905207/qiu-chu-zui-duo-biao-ji-xia-biao-by-leet-0j2m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/