// 795_区间子数组个数.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int lower) {
        int res = 0, cur = 0;
        for (auto x : nums) {
            cur = x <= lower ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/solutions/1986565/qu-jian-zi-shu-zu-ge-shu-by-leetcode-sol-7it1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
