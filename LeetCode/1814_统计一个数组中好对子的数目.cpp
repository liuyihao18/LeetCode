// 1814_统计一个数组中好对子的数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1000000007;
        int res = 0;
        unordered_map<int, int> h;
        for (int i : nums) {
            int temp = i, j = 0;
            while (temp > 0) {
                j = j * 10 + temp % 10;
                temp /= 10;
            }
            res = (res + h[i - j]) % MOD;
            h[i - j]++;
        }
        return res;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/count-nice-pairs-in-an-array/solutions/2064186/tong-ji-yi-ge-shu-zu-zhong-hao-dui-zi-de-ywux/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
