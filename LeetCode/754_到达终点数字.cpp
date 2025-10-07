// 754_到达终点数字.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = static_cast<int>(ceil((-1 + sqrt(8L * target + 1)) / 2)); // 注意 8*target 会超过 int 范围
        return (n * (n + 1) / 2 - target) % 2 == 0 ? n : n + 1 + n % 2;
    }
};
/*
作者：endlesscheng
链接：https ://leetcode.cn/problems/reach-a-number/solution/fen-lei-tao-lun-xiang-xi-zheng-ming-jian-sqj2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
