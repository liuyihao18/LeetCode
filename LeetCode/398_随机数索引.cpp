// 398_随机数索引.cpp
#include "custom.h"
ustd

// 可学习：水塘抽样
// 遍历 nums，当我们第 i 次遇到值为 target 的元素时，随机选择区间 [0,i) 内的一个整数，
// 如果其等于 0，则将返回值置为该元素的下标，否则返回值不变
class Solution {
    map<int, vector<int>> m;

public:
    Solution(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        const vector<int>& v = m[target];
        int n = static_cast<int>(v.size());
        return v[rand() % n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
