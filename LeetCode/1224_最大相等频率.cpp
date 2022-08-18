// 1224_最大相等频率.cpp
#include "custom.h"
ustd

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||
                freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/maximum-equal-frequency/solution/zui-da-xiang-deng-pin-lu-by-leetcode-sol-5y2m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
