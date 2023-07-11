// 1911_最大子序列交替和.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        long long even = nums[0]; // 最后一个数下标为偶数时的和
        long long odd = 0; // 最后一个数下标为奇数时的和
        for (size_t i = 1; i < nums.size(); i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
    }
};

/*
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        /*
        贪心:
        题目要求偶数下标的减去奇数下标的，而且这些是从数组中取的子序列，也就是说可以取也可以不取
        那么就可以看成是股票交易的价格，其中赚的就是差价
        我们贪心地收集每一次能够获利的交易就是答案
        例如:nums = [6,2,1,2,4,5] 我们可以处理成nums = [0,6,2,1,2,4,5]
        在不限制股票交易次数(子序列分割粒度可以到1)的情况下，我们可以将交易粒度最小化，收集每个能够获利的隔天交易
         */
        /*
        long res = 0;
        int pre = 0;    // 前一天价格
        for (int num : nums) {
            // 1.相比于昨天能赚钱
            if (num > pre) res += num - pre;
            // 2.相比于昨天不能赚钱或者亏钱就不买，舍弃
            // 更新下一轮的昨日价格
            pre = num;
        }
        return res;
    }
};
 */
