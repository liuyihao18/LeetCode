// 1764_通过连接另一个数组的子数组得到一个数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool check(vector<int>& g, vector<int>& nums, size_t k) {
        if (k + g.size() > nums.size()) {
            return false;
        }
        for (int j = 0; j < g.size(); j++) {
            if (g[j] != nums[k + j]) {
                return false;
            }
        }
        return true;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i = 0;
        for (size_t k = 0; k < nums.size() && i < groups.size();) {
            if (check(groups[i], nums, k)) {
                k += groups[i].size();
                i++;
            }
            else {
                k++;
            }
        }
        return i == groups.size();
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/form-array-by-concatenating-subarrays-of-another-array/solutions/2022689/tong-guo-lian-jie-ling-yi-ge-shu-zu-de-z-xsvx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
